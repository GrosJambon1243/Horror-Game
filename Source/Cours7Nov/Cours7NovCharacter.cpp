// Copyright Epic Games, Inc. All Rights Reserved.

#include "Cours7NovCharacter.h"
#include "Cours7NovProjectile.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "MyPlayerUi.h"
#include "Blueprint/UserWidget.h"
#include "Engine/LocalPlayer.h"
#include "Kismet/GameplayStatics.h"
#include "PickupInterface.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

//////////////////////////////////////////////////////////////////////////
// ACours7NovCharacter

ACours7NovCharacter::ACours7NovCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);
		
	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-10.f, 0.f, 60.f)); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;
	//Mesh1P->SetRelativeRotation(FRotator(0.9f, -19.19f, 5.2f));
	Mesh1P->SetRelativeLocation(FVector(-30.f, 0.f, -150.f));

}

void ACours7NovCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();
	auto UserWidget = CreateWidget<UUserWidget>(GetWorld(),PlayerWidgetClass);
	PlayerUi = Cast<UMyPlayerUi>(UserWidget);
	PlayerUi -> AddToViewport();
}

void ACours7NovCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (!isInspecting)
	{
		FHitResult Hit;
		FVector Start = FirstPersonCameraComponent->GetComponentLocation();
		FVector End = Start + FirstPersonCameraComponent->GetForwardVector() * 5000.f;
		FCollisionObjectQueryParams QueryParams;
		QueryParams.AddObjectTypesToQuery(ECC_WorldDynamic);

		FCollisionQueryParams Params;
		Params.AddIgnoredActor(this);

		if (GetWorld()->LineTraceSingleByObjectType(Hit,Start,End,QueryParams,Params))
		{
			auto HitActor = Hit.GetActor();
			if (IsValid(HitActor))
			{
				PlayerUi->SetPromptE(true);
				if (HitActor->Implements<UPickupInterface>())
				{
					
				}
			}
		}
		else
		{
			PlayerUi->SetPromptE(false);
		}
	}
}

//////////////////////////////////////////////////////////////////////////// Input

void ACours7NovCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{	
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ACours7NovCharacter::Move);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ACours7NovCharacter::Look);

		//Pause Game
		EnhancedInputComponent->BindAction(PauseAction,ETriggerEvent::Triggered,this, &ACours7NovCharacter::PauseGame);
	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input Component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}


void ACours7NovCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add movement 
		AddMovementInput(GetActorForwardVector(), MovementVector.Y);
		AddMovementInput(GetActorRightVector(), MovementVector.X);
	}
}

void ACours7NovCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void ACours7NovCharacter::PauseGame()
{
	GEngine->AddOnScreenDebugMessage(-1,5.f,FColor::Red,TEXT("Pause!"));
	if (GetWorld()->IsPaused())
	{
		UGameplayStatics::SetGamePaused(GetWorld(),false);
	}
	else
	{
		UGameplayStatics::SetGamePaused(GetWorld(),true);
	}
	
}

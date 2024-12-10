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
#include "LockUi.h"
#include "MainMenu.h"
#include "MyPlayerUi.h"
#include "Blueprint/UserWidget.h"
#include "Engine/LocalPlayer.h"
#include "Kismet/GameplayStatics.h"
#include "PickupInterface.h"
#include "PauseMenu.h"
#include "Prison_Key.h"
#include "Prison_Door.h"
#include "Carpet.h"
#include "GameIntro.h"
#include "Skull.h"

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
	AttachPoint = CreateDefaultSubobject<USceneComponent>("Attach Point");
	AttachPoint->SetupAttachment(GetCapsuleComponent());

	InspectPoint = CreateDefaultSubobject<USceneComponent>("InspectPoint");
	InspectPoint->SetupAttachment(FirstPersonCameraComponent);

}

void ACours7NovCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();
	auto UserWidget = CreateWidget<UUserWidget>(GetWorld(),PlayerWidgetClass);
	PlayerUi = Cast<UMyPlayerUi>(UserWidget);
	PlayerUi -> AddToViewport();

	auto PauseMenu = CreateWidget<UUserWidget>(GetWorld(),PauseMenuWidgetClass);
	PauseUi = Cast<UPauseMenu>(PauseMenu);
	PauseUi -> AddToViewport();
	PauseUi->SetVisibility(ESlateVisibility::Hidden);
	
	auto LockWidget = CreateWidget(GetWorld(),LockUiWidgetClass);
	LockUi = Cast<ULockUi>(LockWidget);
	LockUi -> AddToViewport();
	LockUi->SetVisibility(ESlateVisibility::Hidden);

	auto MainMenuWidget = CreateWidget(GetWorld(),MainMenuWidgetClass);
	MainMenuUi = Cast<UMainMenu>(MainMenuWidget);

	auto IntroWidget = CreateWidget(GetWorld(),IntroWidgetClass);
	IntroWidgetUi = Cast<UGameIntro>(IntroWidget);
	IntroWidgetUi ->AddToViewport();
	

	key = nullptr;
	
	//MainMenuUi->AddToViewport();

	//Uncomment pour test le main menu
	UGameplayStatics::SetGamePaused(GetWorld(),true);
	GetLocalViewingPlayerController()->SetShowMouseCursor(true);

	
}

void ACours7NovCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	if (!isInspecting)
	{
		
		FVector Start = FirstPersonCameraComponent->GetComponentLocation();
		FVector End = Start + FirstPersonCameraComponent->GetForwardVector() * 300.f;
		FCollisionObjectQueryParams QueryParams;
		QueryParams.AddObjectTypesToQuery(ECC_WorldDynamic);

		FCollisionQueryParams Params;
		Params.AddIgnoredActor(this);

		if (GetWorld()->LineTraceSingleByObjectType(Hit,Start,End,QueryParams,Params))
		{
			HitActor = Hit.GetActor();
			if (IsValid(HitActor) && HitActor->Implements<UPickupInterface>())
			{
				PlayerUi->SetPromptE(true,"Press E To Pick Up");
			}
			if (IsValid(HitActor) && HitActor->Implements<UOpenable>())
			{
				PlayerUi->SetPromptE(true,"Press E To Open");
			}
			if (IsValid(HitActor) && Cast<ACarpet>(HitActor))
			{
				PlayerUi->SetPromptE(true,"Press E To Remove");
			}
			if (IsValid(HitActor) && Cast<ASkull>(HitActor))
			{
				PlayerUi->SetPromptE(true,"Press E To Inspect The Strange Skull");
				CurrentInspectingActor = HitActor;
			}
			
		}
		else
		{
			PlayerUi->SetPromptE(false,"");
			HitActor = nullptr;
			CurrentInspectingActor = nullptr;
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

		//Pick Up Object
		EnhancedInputComponent->BindAction(PickUpAction,ETriggerEvent::Triggered,this, &ACours7NovCharacter::PickupFunction);
		
		//Change View
		EnhancedInputComponent->BindAction(ChangeView,ETriggerEvent::Triggered,this, &ACours7NovCharacter::ChangeViewFunction);
		
		//Rotate Object
		EnhancedInputComponent->BindAction(RotateInspect, ETriggerEvent::Triggered, this, &ACours7NovCharacter::RotateInspectObj);

		//Exit Inspect Mode
		EnhancedInputComponent->BindAction(ExitInspect, ETriggerEvent::Triggered, this, &ACours7NovCharacter::ExitingInspectMode);
	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input Component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void ACours7NovCharacter::RemoveIntro()
{
	GetLocalViewingPlayerController()->SetShowMouseCursor(false);
	UGameplayStatics::SetGamePaused(GetWorld(),false);
}


void ACours7NovCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr )
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

void ACours7NovCharacter::RotateInspectObj(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();
	//FRotator ObjRotator = CurrentInspectingActor->GetActorRotation();
	FRotator LoRotator (LookAxisVector.Y,LookAxisVector.X,0.0f);
	if (Controller != nullptr && CurrentInspectingActor)
	{
		CurrentInspectingActor->AddActorLocalRotation(LoRotator,false);
	}
}

void ACours7NovCharacter::PauseGame()
{
	GEngine->AddOnScreenDebugMessage(-1,5.f,FColor::Red,TEXT("Pause!"));
	if (GetWorld()->IsPaused())
	{
		UGameplayStatics::SetGamePaused(GetWorld(),false);
		PauseUi->SetVisibility(ESlateVisibility::Hidden);
		GetLocalViewingPlayerController()->SetShowMouseCursor(false);
	}
	else
	{
		UGameplayStatics::SetGamePaused(GetWorld(),true);
		PauseUi->SetVisibility(ESlateVisibility::Visible);
		GetLocalViewingPlayerController()->SetShowMouseCursor(true);
		
	}
	
}

void ACours7NovCharacter::PickupFunction()
{


	if (IsValid(HitActor)&&HitActor->GetName() == "BP_NUmLock_C_UAID_7C10C92358ABED3202_1186069007")
	{
		LockUi->SetVisibility(ESlateVisibility::Visible);
		
		GetLocalViewingPlayerController()->SetShowMouseCursor(true);
		UGameplayStatics::SetGamePaused(GetWorld(),true);
	}
		
	
	if (IsValid(HitActor) && Cast<APrison_Key>(HitActor))
	{
		const auto attach = FAttachmentTransformRules::SnapToTargetIncludingScale;
		key = HitActor;
		key->AttachToComponent(AttachPoint,attach);
		hasKey = true;
		UE_LOG(LogTemp, Warning, TEXT("Key PickUp"));
	}
	if (IsValid(HitActor) && Cast<APrison_Door>(HitActor) && hasKey)
	{
		Cast<APrison_Door>(HitActor)->OpenDoor(70);
		key->Destroy();
		hasKey = false;
		PlayerUi->SetPromptQuest("Talk to the stranger");
		UE_LOG(LogTemp, Warning, TEXT("Door open"));
	}
	if (IsValid(HitActor) && Cast<ACarpet>(HitActor))
	{
		HitActor->Destroy();
	}
	if (!isInspecting && CurrentInspectingActor)
	{
		isInspecting = true;
		PlayerUi->SetPromptE(false,"");
		InspectPoint->SetRelativeRotation(FRotator::ZeroRotator);
		InitialInspectTrans = CurrentInspectingActor->GetActorTransform();
		CurrentInspectingActor->AttachToComponent(InspectPoint,FAttachmentTransformRules::SnapToTargetNotIncludingScale);

		//Changement Context
		const auto PlayerController = Cast<APlayerController>(GetController());
		auto InputSys = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());

		InputSys->RemoveMappingContext(DefaultMC);
		InputSys->AddMappingContext(InspectMC,0);
		UE_LOG(LogTemp, Warning, TEXT("Inspect Mode"));
		
	}
	
}

void ACours7NovCharacter::ChangeViewFunction()
{
	GEngine->AddOnScreenDebugMessage(-1,5.f,FColor::Red,TEXT("View Changed"));
	if (isChangeView)
	{
		isChangeView = false;
	}
	else
	{
		isChangeView = true;
	}
	if (FirstPersonCameraComponent && isChangeView == true)
	{
		UE::Math::TVector4<double> vector(0.9f,0.9f,0.9f,0.9f);
		FirstPersonCameraComponent->PostProcessSettings.bOverride_FilmGrainIntensity = true;
		FirstPersonCameraComponent->PostProcessSettings.bOverride_SceneFringeIntensity = true;
		FirstPersonCameraComponent->PostProcessSettings.bOverride_ColorContrast = true;
		FirstPersonCameraComponent->PostProcessSettings.ColorContrast = vector;
		FirstPersonCameraComponent->PostProcessSettings.FilmGrainIntensity = 1.0f;
		FirstPersonCameraComponent->PostProcessSettings.SceneFringeIntensity = 3.0f;
		
		
		FirstPersonCameraComponent->PostProcessBlendWeight = 1.0f;

		
	}else if (isChangeView == false)
	{
		FirstPersonCameraComponent->PostProcessSettings.FilmGrainIntensity = 0.0f;
		FirstPersonCameraComponent->PostProcessSettings.SceneFringeIntensity = 0.0f;
		FirstPersonCameraComponent->PostProcessSettings.ColorContrast = UE::Math::TVector4<double>(1.0f,1.0f,1.0f,1.0f);
	}

}

void ACours7NovCharacter::ExitingInspectMode()
{
	if (isInspecting)
	{
		isInspecting = false;
		CurrentInspectingActor->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
		CurrentInspectingActor->SetActorTransform(InitialInspectTrans);
		CurrentInspectingActor = nullptr;
		
		const auto PlayerController = Cast<APlayerController>(GetController());
		const auto InputSys = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
		InputSys->RemoveMappingContext(InspectMC);
		InputSys->AddMappingContext(DefaultMC,0);
	}
}

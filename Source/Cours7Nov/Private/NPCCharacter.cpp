// Fill out your copyright notice in the Description page of Project Settings.


#include "NPCCharacter.h"
#include "NpcDialogue.h"
#include "Components/TextRenderComponent.h"

// Sets default values
ANPCCharacter::ANPCCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;
	Dialogue = CreateDefaultSubobject<UTextRenderComponent>("TextComp");
	Dialogue->SetupAttachment(RootComponent);
	
}

// Called when the game starts or when spawned
void ANPCCharacter::BeginPlay()
{
	Super::BeginPlay();
	DialogueRowHandle.DataTable->GetAllRows("",AllDialo);
	Dialogue->SetText(AllDialo[0]->DialogueText);
	maxTimer = timer;
	
}

// Called every frame
void ANPCCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (timer<= maxTimer)
	{
		timer -= DeltaTime;
		if (timer<=0)
		{
			index++;
			Dialogue->SetText(AllDialo[index]->DialogueText);
			timer = maxTimer;
			if (index == AllDialo.Num()-1)
			{
				Dialogue->SetText(lastMess);
				timer = maxTimer*2;
			}
		}
	}

}

// Called to bind functionality to input
void ANPCCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ANPCCharacter::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp,
	bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);

	//Faire Jouer montage
	GetMesh()->GetAnimInstance()->Montage_Play(HitAnimMontage);
	
}


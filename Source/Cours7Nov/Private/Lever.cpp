// Fill out your copyright notice in the Description page of Project Settings.


#include "Lever.h"

#include "WoodenDoor.h"
#include "Components/PointLightComponent.h"

// Sets default values
ALever::ALever()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SceneRoot = CreateDefaultSubobject<USceneComponent>("SceneComp");
	RootComponent = SceneRoot;
	Base = CreateDefaultSubobject<UStaticMeshComponent>("Chest");
	Base->SetupAttachment(SceneRoot);
	LeverRoot = CreateDefaultSubobject<USceneComponent>("LeverBase");
	LeverRoot ->SetupAttachment(Base);
	Lever = CreateDefaultSubobject<UStaticMeshComponent>("Lever");
	Lever ->SetupAttachment(LeverRoot);
	Light = CreateDefaultSubobject<UPointLightComponent>("Light");
	Light->SetupAttachment(Base);

}

// Called when the game starts or when spawned
void ALever::BeginPlay()
{
	Super::BeginPlay();
	Light->SetLightColor(FLinearColor::Red);
}

// Called every frame
void ALever::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALever::LeverActive()
{
	if (!isUnlock)
	{
		isUnlock = true;
		TheDoor->RedisterLever(LeverId);
		Light->SetLightColor(FLinearColor::Green);
		UE_LOG(LogTemp, Warning, TEXT("%i"), LeverId);
	}
}

void ALever::ResetLever()
{
	Light->SetLightColor(FLinearColor::Red);
	isUnlock = false;
}


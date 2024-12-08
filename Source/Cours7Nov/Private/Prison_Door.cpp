// Fill out your copyright notice in the Description page of Project Settings.


#include "Prison_Door.h"

// Sets default values
APrison_Door::APrison_Door()
{
 	
	PrimaryActorTick.bCanEverTick = true;
	SceneRoot = CreateDefaultSubobject<USceneComponent>("SceneComp");
	RootComponent = SceneRoot;

	RotatingPoint = CreateDefaultSubobject<USceneComponent>("Rotating Point");
	RotatingPoint->SetupAttachment(SceneRoot);

	Door = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorComp"));
	Door-> SetupAttachment(RotatingPoint);

	Hinge1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Hinge1"));
	Hinge1 -> SetupAttachment(Door);

	Hinge2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Hinge2"));
	Hinge2 -> SetupAttachment(Door);

}

// Called when the game starts or when spawned
void APrison_Door::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APrison_Door::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APrison_Door::OpenDoor(float Rotate) const
{
	RotatingPoint->SetWorldRotation(FRotator (0,Rotate,0),true);
}



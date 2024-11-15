// Fill out your copyright notice in the Description page of Project Settings.


#include "Prison_Door.h"

// Sets default values
APrison_Door::APrison_Door()
{
 	
	PrimaryActorTick.bCanEverTick = true;
	SceneRoot = CreateDefaultSubobject<USceneComponent>("SceneComp");
	RootComponent = SceneRoot;

	Door = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorComp"));
	Door-> SetupAttachment(SceneRoot);

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


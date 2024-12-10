// Fill out your copyright notice in the Description page of Project Settings.


#include "Prison_Key.h"

// Sets default values
APrison_Key::APrison_Key()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SceneRoot = CreateDefaultSubobject<USceneComponent>("SceneComp");
	RootComponent = SceneRoot;

	Key = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Key"));
	Key-> SetupAttachment(SceneRoot);

	KeyPart1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Hole"));
	KeyPart1 -> SetupAttachment(Key);

	KeyPart2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cylinder"));
	KeyPart2 -> SetupAttachment(Key);

	KeyPart3 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EndOfKey"));
	KeyPart3 -> SetupAttachment(Key);

}

// Called when the game starts or when spawned
void APrison_Key::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APrison_Key::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}





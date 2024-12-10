// Fill out your copyright notice in the Description page of Project Settings.


#include "Skull.h"

// Sets default values
ASkull::ASkull()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SceneRoot = CreateDefaultSubobject<USceneComponent>("SceneComp");
	RootComponent = SceneRoot;
	Skull = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Skull"));
	Skull-> SetupAttachment(SceneRoot);
	Collider = CreateDefaultSubobject<UCapsuleComponent>("Collider");
	Collider ->SetupAttachment(Skull);

}

// Called when the game starts or when spawned
void ASkull::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASkull::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


// Fill out your copyright notice in the Description page of Project Settings.


#include "NumLock.h"

#include "LockUi.h"
#include "NavigationSystemTypes.h"
#include "Blueprint/UserWidget.h"

// Sets default values
ANumLock::ANumLock()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SceneRoot = CreateDefaultSubobject<USceneComponent>("SceneComp");
	RootComponent = SceneRoot;

	Chest = CreateDefaultSubobject<UStaticMeshComponent>("Chest");
	Chest->SetupAttachment(SceneRoot);

	Collision = CreateDefaultSubobject<UBoxComponent>("Collision");
	Collision->SetupAttachment(Chest);

}

// Called when the game starts or when spawned
void ANumLock::BeginPlay()
{
	Super::BeginPlay();
	
	
}

// Called every frame
void ANumLock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


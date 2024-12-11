// Fill out your copyright notice in the Description page of Project Settings.


#include "Plateforme.h"

#include "Components/PointLightComponent.h"

// Sets default values
APlateforme::APlateforme()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SceneRoot = CreateDefaultSubobject<USceneComponent>("SceneComp");
	RootComponent = SceneRoot;

	Plateforme = CreateDefaultSubobject<UStaticMeshComponent>("Body");
	Plateforme->SetupAttachment(SceneRoot);

	Light = CreateDefaultSubobject<UPointLightComponent>("Light");
	Light->SetupAttachment(Plateforme);

}

// Called when the game starts or when spawned
void APlateforme::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlateforme::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlateforme::hidePlatforme(bool visible)
{
	Plateforme->SetVisibility(visible);
	Light->SetVisibility(visible);
}


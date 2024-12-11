// Fill out your copyright notice in the Description page of Project Settings.


#include "Torche.h"

#include "Components/PointLightComponent.h"
#include "NiagaraComponent.h"

// Sets default values
ATorche::ATorche()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SceneRoot = CreateDefaultSubobject<USceneComponent>("SceneComp");
	RootComponent = SceneRoot;

	TorcheBody = CreateDefaultSubobject<UStaticMeshComponent>("Body");
	TorcheBody->SetupAttachment(SceneRoot);

	Light = CreateDefaultSubobject<UPointLightComponent>("Light");
	Light->SetupAttachment(TorcheBody);

	Fire = CreateDefaultSubobject<UNiagaraComponent>("Fire");
	Fire -> SetupAttachment(TorcheBody);
}

// Called when the game starts or when spawned
void ATorche::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATorche::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


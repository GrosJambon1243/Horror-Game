// Fill out your copyright notice in the Description page of Project Settings.


#include "MusicManager.h"

#include "Components/AudioComponent.h"

// Sets default values
AMusicManager::AMusicManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SceneRoot = CreateDefaultSubobject<USceneComponent>("SceneComp");
	RootComponent = SceneRoot;

	

}

// Called when the game starts or when spawned
void AMusicManager::BeginPlay()
{
	Super::BeginPlay();
	if (BackgroundMusic)
	{
		if (!AudioComponent)
		{
			AudioComponent = NewObject<UAudioComponent>(this);
			AudioComponent->RegisterComponent();
		}
		AudioComponent->SetSound(BackgroundMusic);
		AudioComponent->SetVolumeMultiplier(0.2f);
		AudioComponent->Play();
	}
	
}

// Called every frame
void AMusicManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMusicManager::AdjustVolume(float volume)
{
	if (AudioComponent)
	{
		AudioComponent->SetVolumeMultiplier(volume);
	}
}


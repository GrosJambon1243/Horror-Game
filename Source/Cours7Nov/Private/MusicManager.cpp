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
	if (KeySfx)
	{
		if (!KeyAudioComponent)
		{
			KeyAudioComponent = NewObject<UAudioComponent>(this);
			KeyAudioComponent ->RegisterComponent();
		}
		KeyAudioComponent->SetSound(KeySfx);
		KeyAudioComponent->SetVolumeMultiplier(sfxVolume);
	}
	if (DoorSfx)
	{
		if (!DoorAudioComponent)
		{
			DoorAudioComponent = NewObject<UAudioComponent>(this);
			DoorAudioComponent ->RegisterComponent();
		}
		DoorAudioComponent->SetSound(DoorSfx);
		DoorAudioComponent->SetVolumeMultiplier(sfxVolume);
	}
	if (LeverSfx)
	{
		if (!LeverAudioComponent)
		{
			LeverAudioComponent = NewObject<UAudioComponent>(this);
			LeverAudioComponent ->RegisterComponent();
		}
		LeverAudioComponent->SetSound(KeySfx);
		LeverAudioComponent->SetVolumeMultiplier(sfxVolume);
	}
	if (PowerSfx)
	{
		if (!PowerAudioComponent)
		{
			PowerAudioComponent = NewObject<UAudioComponent>(this);
			PowerAudioComponent ->RegisterComponent();
			
		}
		PowerAudioComponent->SetSound(PowerSfx);
		PowerAudioComponent->SetVolumeMultiplier(sfxVolume);
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

void AMusicManager::AdjustSfx(float volume)
{
	if (KeyAudioComponent && DoorAudioComponent && LeverAudioComponent)
	{
		KeyAudioComponent->SetVolumeMultiplier(volume);
		DoorAudioComponent->SetVolumeMultiplier(volume);
		LeverAudioComponent->SetVolumeMultiplier(volume);
	}
}

void AMusicManager::PlayKeySfx()
{
	KeyAudioComponent->Play();
}

void AMusicManager::PlayDoorSfx()
{
	DoorAudioComponent->Play();
}

void AMusicManager::PlayLeverSfx()
{
	LeverAudioComponent->Play();
}

void AMusicManager::PlayPowerSfx()
{
	PowerAudioComponent->Play();
}


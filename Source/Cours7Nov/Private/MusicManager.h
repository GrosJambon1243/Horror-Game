// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MusicManager.generated.h"

UCLASS()
class AMusicManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMusicManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")
	USoundBase* BackgroundMusic;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")
	USoundBase* KeySfx;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")
	USoundBase* DoorSfx;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")
	USoundBase* LeverSfx;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")
	USoundBase* PowerSfx;

	UAudioComponent* AudioComponent;

	UAudioComponent* KeyAudioComponent;

	UAudioComponent* DoorAudioComponent;

	UAudioComponent* LeverAudioComponent;
	
	UAudioComponent* PowerAudioComponent;
	
	UPROPERTY(EditAnywhere)
	USceneComponent* SceneRoot;

	void AdjustVolume(float volume);
	
	void AdjustSfx(float volume);

	void PlayKeySfx();

	void PlayDoorSfx();

	void PlayLeverSfx();

	void PlayPowerSfx();

	float sfxVolume = 0.5f;

};

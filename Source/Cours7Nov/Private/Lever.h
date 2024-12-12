// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PickupInterface.h"
#include "GameFramework/Actor.h"
#include "Lever.generated.h"

class AWoodenDoor;
class UBoxComponent;

UCLASS()
class ALever : public AActor, public IPickupInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALever();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(VisibleAnywhere)
	USceneComponent* SceneRoot;
	UPROPERTY(VisibleAnywhere)
	USceneComponent* LeverRoot;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Base;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Lever;
	bool isUnlock = false;
	UPROPERTY(EditAnywhere)
	int LeverId;
	UPROPERTY(EditAnywhere)
	AWoodenDoor* TheDoor;
	UPROPERTY(VisibleAnywhere)
	class UPointLightComponent* Light;

	void LeverActive();
	void ResetLever();

};

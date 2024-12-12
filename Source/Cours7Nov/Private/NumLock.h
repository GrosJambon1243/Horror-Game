// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NativeGameplayTags.h"
#include "PickupInterface.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "NumLock.generated.h"

UCLASS()
class ANumLock : public AActor, public IPickupInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANumLock();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(VisibleAnywhere)
	USceneComponent* SceneRoot;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Chest;
	UPROPERTY(VisibleAnywhere)
	UBoxComponent* Collision;

};

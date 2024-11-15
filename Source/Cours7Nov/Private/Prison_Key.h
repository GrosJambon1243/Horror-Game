// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PickupInterface.h"
#include "GameFramework/Actor.h"
#include "Prison_Key.generated.h"

UCLASS()
class APrison_Key : public AActor, public IPickupInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APrison_Key();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* SceneRoot;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Key;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* KeyPart1;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* KeyPart2;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* KeyPart3;

};

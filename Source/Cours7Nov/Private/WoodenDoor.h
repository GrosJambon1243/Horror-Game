// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WoodenDoor.generated.h"

class ALever;

UCLASS()
class AWoodenDoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWoodenDoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(VisibleAnywhere)
	USceneComponent* SceneRoot;
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Door1AttachPoint;
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Door2AttachPoint;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Door1;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Door2; 
	UPROPERTY(EditAnywhere)
	TArray<ALever*> AllLevers;

	TArray<int> CorrectOrder = {2,3,1,4};

	TArray<int> ActivationOrder;
	void RedisterLever(int Id);
	bool isOpen = false;
	float lerpValue;
	float time;


	
};

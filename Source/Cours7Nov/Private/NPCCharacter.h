// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NPCCharacter.generated.h"
struct FNpcDialogueData;
class UTextRenderComponent;


UCLASS()
class ANPCCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANPCCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UAnimMontage> HitAnimMontage;
	UPROPERTY(VisibleAnywhere)
	UTextRenderComponent* Dialogue;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	FDataTableRowHandle DialogueRowHandle;

	TArray<FNpcDialogueData*> AllDialo;
	int index = 0;
	float timer = 10.0f;
	float maxTimer = 0.0f;
	FText lastMess = FText::FromString(TEXT("Good luck....(Press 1 to use your ability)"));
	
	
};

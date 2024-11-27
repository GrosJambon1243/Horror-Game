// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LockUi.generated.h"

/**
 * 
 */
UCLASS()
class ULockUi : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual void NativeConstruct() override;
	UPROPERTY(meta=(BindWidget))
	class UButton* UpArrow;
	UPROPERTY(meta=(BindWidget))
	class UButton* DownArrow;
	UPROPERTY(meta=(BindWidget))
	class UTextBlock* TextFirtCol;

	int firstNum = 0;
	int secNum = 0;
	int thirdNum = 0;

	UFUNCTION()
	void OnClickUp();

	UFUNCTION()
	void OnClickDonw();
	
};

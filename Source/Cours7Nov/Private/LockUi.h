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
	
	UPROPERTY(meta=(BindWidget))
	class UButton* UpArrow_1;
	UPROPERTY(meta=(BindWidget))
	class UButton* DownArrow_1;
	UPROPERTY(meta=(BindWidget))
	class UTextBlock* TextFirtCol_1;
	
	UPROPERTY(meta=(BindWidget))
	class UButton* UpArrow_2;
	UPROPERTY(meta=(BindWidget))
	class UButton* DownArrow_2;
	UPROPERTY(meta=(BindWidget))
	class UTextBlock* TextFirtCol_2;

	UPROPERTY(meta=(BindWidget))
	class UButton* Open;
	UPROPERTY(meta=(BindWidget))
	class UButton* Close;

	
	AActor* ThePLayer;
	int firstNum = 0;
	int secNum = 0;
	int thirdNum = 0;

	
	UFUNCTION()
	void OnClickUp();

	UFUNCTION()
	void OnClickDonw();
	
	UFUNCTION()
	void OnClickUp1();

	UFUNCTION()
	void OnClickDonw1();
	
	UFUNCTION()
	void OnClickUp2();

	UFUNCTION()
	void OnClickDonw2();

	UFUNCTION()
	void OnUnlock();

	UFUNCTION()
	void OnClose();
	
};

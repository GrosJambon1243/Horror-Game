// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class UMainMenu : public UUserWidget
{
	GENERATED_BODY()
	virtual void NativeConstruct() override;
	UPROPERTY(meta=(BindWidget))
	class UButton* Quit;
	UPROPERTY(meta=(BindWidget))
	class UButton* Start;
	UFUNCTION()
	void EndGame();
	UFUNCTION()
	void StartGame();
	
};

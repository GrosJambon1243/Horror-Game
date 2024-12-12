// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EndGame.generated.h"

/**
 * 
 */
UCLASS()
class UEndGame : public UUserWidget
{
	GENERATED_BODY()
	virtual void NativeConstruct() override;
public:
	UPROPERTY(meta=(BindWidget))
	class UButton* Quit;
	UFUNCTION()
	void OnQuit();
};

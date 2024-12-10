// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameIntro.generated.h"

struct FDialogueData;
/**
 * 
 */
UCLASS()
class UGameIntro : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	FDataTableRowHandle Dialogue;
	UPROPERTY(meta=(BindWidget))
	class UButton* Next;
	UPROPERTY(meta=(BindWidget))
	class UButton* Previous;
	UPROPERTY(meta=(BindWidget))
	class UButton* Skip;
	UPROPERTY(meta=(BindWidget))
	class UTextBlock* TextSpace;

	UFUNCTION()
	void OnNextClick();
	UFUNCTION()
	void OnPreviousClick();
	UFUNCTION()
	void OnSkipClick();
	
	AActor* ThePLayer;

	TArray<FDialogueData*> DialogueDatas;
	int index = 0;
	
};

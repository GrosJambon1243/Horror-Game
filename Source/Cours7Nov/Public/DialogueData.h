#pragma once
#include "CoreMinimal.h"
#include "DialogueData.generated.h"

USTRUCT(BlueprintType)
struct COURS7NOV_API FDialogueData : public FTableRowBase
{
	GENERATED_BODY()
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int DialogueId;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText DialogueText;
	
	
};
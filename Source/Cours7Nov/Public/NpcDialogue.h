#pragma once
#include "CoreMinimal.h"
#include "NpcDialogue.generated.h"

USTRUCT(BlueprintType)
struct COURS7NOV_API FNpcDialogueData : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText DialogueText;
	
	
};
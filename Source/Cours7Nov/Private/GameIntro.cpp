// Fill out your copyright notice in the Description page of Project Settings.


#include "GameIntro.h"

#include "DialogueData.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Cours7Nov/Cours7NovCharacter.h"
#include "Kismet/GameplayStatics.h"

void UGameIntro::NativeConstruct()
{
	Super::NativeConstruct();
	
	Dialogue.DataTable->GetAllRows("",DialogueDatas);

	
	Next->OnClicked.AddDynamic(this,&UGameIntro::OnNextClick);
	Previous->OnClicked.AddDynamic(this,&UGameIntro::OnPreviousClick);
	Skip->OnClicked.AddDynamic(this,&UGameIntro::OnSkipClick);
	TextSpace->SetText(DialogueDatas[0]->DialogueText);
	ThePLayer = UGameplayStatics::GetPlayerCharacter(GetWorld(),0);
}

void UGameIntro::OnNextClick()
{
	if (index < DialogueDatas.Num())
	{
		index++;
		if(index>=5)
		{
			index = 4;
			OnSkipClick();
		}
		TextSpace->SetText(DialogueDatas[index]->DialogueText);
		
		
	}
	

}

void UGameIntro::OnPreviousClick()
{
	if (index >=0)
	{
		index--;
		if (index <0)
		{
			index = 0;
		}
		TextSpace->SetText(DialogueDatas[index]->DialogueText);
		
		
	}
	
	
	
}

void UGameIntro::OnSkipClick()
{
	if (ThePLayer)
	{
		Cast<ACours7NovCharacter>(ThePLayer)->RemoveIntro();
	}
	
	this->SetVisibility(ESlateVisibility::Hidden);
}

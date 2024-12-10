// Fill out your copyright notice in the Description page of Project Settings.


#include "LockUi.h"

#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Cours7Nov/Cours7NovCharacter.h"
#include "Kismet/GameplayStatics.h"

void ULockUi::NativeConstruct()
{
	Super::NativeConstruct();
	UpArrow->OnClicked.AddDynamic(this,&ULockUi::OnClickUp);
	DownArrow->OnClicked.AddDynamic(this,&ULockUi::OnClickDonw);

	UpArrow_1->OnClicked.AddDynamic(this,&ULockUi::OnClickUp1);
	DownArrow_1->OnClicked.AddDynamic(this,&ULockUi::OnClickDonw1);

	UpArrow_2->OnClicked.AddDynamic(this,&ULockUi::OnClickUp2);
	DownArrow_2->OnClicked.AddDynamic(this,&ULockUi::OnClickDonw2);

	Open->OnClicked.AddDynamic(this,&ULockUi::OnUnlock);
	Close->OnClicked.AddDynamic(this,&ULockUi::OnClose);
	ThePLayer = UGameplayStatics::GetPlayerCharacter(GetWorld(),0);
	
}

void ULockUi::OnClickUp()
{
	firstNum++;
	if (firstNum>9)
	{
		firstNum = 9;
	}
	FText updateText = FText::AsNumber(firstNum);
	TextFirtCol->SetText(updateText);
}

void ULockUi::OnClickDonw()
{
	firstNum--;
	if (firstNum<0)
	{
		firstNum = 0;
	}
	FText updateText = FText::AsNumber(firstNum);
	TextFirtCol->SetText(updateText);
}

void ULockUi::OnClickUp1()
{
	secNum++;
	if (secNum>9)
	{
		secNum = 9;
	}
	FText updateText = FText::AsNumber(secNum);
	TextFirtCol_1->SetText(updateText);
}

void ULockUi::OnClickDonw1()
{
	secNum--;
	if (secNum<0)
	{
		secNum = 0;
	}
	FText updateText = FText::AsNumber(secNum);
	TextFirtCol_1->SetText(updateText);
}

void ULockUi::OnClickUp2()
{
	thirdNum++;
	if (thirdNum>9)
	{
		thirdNum = 9;
	}
	FText updateText = FText::AsNumber(thirdNum);
	TextFirtCol_2->SetText(updateText);
}

void ULockUi::OnClickDonw2()
{
	thirdNum--;
	if (thirdNum<0)
	{
		thirdNum = 0;
	}
	FText updateText = FText::AsNumber(thirdNum);
	TextFirtCol_2->SetText(updateText);
}

void ULockUi::OnUnlock()
{
	if (firstNum == 7 && secNum == 3 && thirdNum == 9)
	{
		UE_LOG(LogTemp, Warning, TEXT("Unlock"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Wrong"));
	}
}

void ULockUi::OnClose()
{
	if (ThePLayer)
	{
		Cast<ACours7NovCharacter>(ThePLayer)->RemoveIntro();
		this->SetVisibility(ESlateVisibility::Hidden);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Pas Lol"));
	}
	
}

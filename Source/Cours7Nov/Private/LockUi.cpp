// Fill out your copyright notice in the Description page of Project Settings.


#include "LockUi.h"

#include "Components/Button.h"
#include "Components/TextBlock.h"

void ULockUi::NativeConstruct()
{
	Super::NativeConstruct();
	if (UpArrow)
	{
		UpArrow->OnClicked.AddDynamic(this,&ULockUi::OnClickUp);
	}
	if (DownArrow)
	{
		DownArrow->OnClicked.AddDynamic(this,&ULockUi::OnClickDonw);
	}
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

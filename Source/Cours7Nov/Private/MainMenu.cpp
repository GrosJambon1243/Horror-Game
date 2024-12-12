// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu.h"

#include "Components/Button.h"
#include "Kismet/KismetSystemLibrary.h"

void UMainMenu::NativeConstruct()
{
	Super::NativeConstruct();
	Quit->OnClicked.AddDynamic(this,&UMainMenu::EndGame);
	Start->OnClicked.AddDynamic(this,&UMainMenu::StartGame);
}

void UMainMenu::EndGame()
{
	UE_LOG(LogTemp, Warning, TEXT("Door"));
	UKismetSystemLibrary::QuitGame(this,nullptr,EQuitPreference::Quit,false);
}

void UMainMenu::StartGame()
{
	this->SetVisibility(ESlateVisibility::Hidden);
}



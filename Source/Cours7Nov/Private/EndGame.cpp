// Fill out your copyright notice in the Description page of Project Settings.


#include "EndGame.h"

#include "Components/Button.h"
#include "Kismet/KismetSystemLibrary.h"

void UEndGame::NativeConstruct()
{
	Super::NativeConstruct();
	Quit->OnClicked.AddDynamic(this,&UEndGame::OnQuit);
}

void UEndGame::OnQuit()
{
	UE_LOG(LogTemp, Warning, TEXT("Door"));
	UKismetSystemLibrary::QuitGame(this,nullptr,EQuitPreference::Quit,false);
}

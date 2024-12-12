// Fill out your copyright notice in the Description page of Project Settings.


#include "PauseMenu.h"

#include "MusicManager.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UPauseMenu::NativeConstruct()
{
	Super::NativeConstruct();
	PlayerController = GetOwningPlayer();
	
	MusicManager = Cast<AMusicManager>(UGameplayStatics::GetActorOfClass(GetWorld(),AMusicManager::StaticClass()));
	
	MouseSlider->OnValueChanged.AddDynamic(this,&UPauseMenu::OnSliderValueChanged);
	MusicSlider ->OnValueChanged.AddDynamic(this,&UPauseMenu::OnMusicSliderValueChanged);
	ContinueButton->OnClicked.AddDynamic(this,&UPauseMenu::OnClicked);
	QuitButton->OnClicked.AddDynamic(this,&UPauseMenu::Quit);
	
}

void UPauseMenu::OnSliderValueChanged(float value)
{
	
	if (PlayerController)
	{
		PlayerController->InputYawScale_DEPRECATED = value;
		PlayerController->InputPitchScale_DEPRECATED = -value;
	}
}

void UPauseMenu::OnMusicSliderValueChanged(float value)
{
	if (MusicManager)
	{
		MusicManager->AdjustVolume(value);
		
	}
}

void UPauseMenu::OnClicked()
{
	UGameplayStatics::SetGamePaused(GetWorld(),false);
	this->SetVisibility(ESlateVisibility::Hidden);
	GetOwningPlayer()->SetShowMouseCursor(false);
	UE_LOG(LogTemp, Warning, TEXT("Continue"));
}

void UPauseMenu::Quit()
{
	UE_LOG(LogTemp, Warning, TEXT("Slider Value Not"));
	UKismetSystemLibrary::QuitGame(this,nullptr,EQuitPreference::Quit,false);
}

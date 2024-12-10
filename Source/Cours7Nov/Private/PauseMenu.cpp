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
	
	if (MouseSlider)
	{
		MouseSlider->OnValueChanged.AddDynamic(this,&UPauseMenu::OnSliderValueChanged);
	}
	if (MusicSlider)
	{
		MusicSlider ->OnValueChanged.AddDynamic(this,&UPauseMenu::OnMusicSliderValueChanged);
	}
	if (ContinueButton)
	{
		ContinueButton->OnClicked.AddDynamic(this,&UPauseMenu::OnClicked);
	}
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
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Slider Value Not"));
	}
	
	
}

void UPauseMenu::OnClicked()
{
	UGameplayStatics::SetGamePaused(GetWorld(),false);
	this->SetVisibility(ESlateVisibility::Hidden);
	GetOwningPlayer()->SetShowMouseCursor(false);
	UE_LOG(LogTemp, Warning, TEXT("Continue"));
}

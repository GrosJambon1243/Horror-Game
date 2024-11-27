// Fill out your copyright notice in the Description page of Project Settings.


#include "PauseMenu.h"

#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UPauseMenu::NativeConstruct()
{
	Super::NativeConstruct();
	PlayerController = GetOwningPlayer();

	if (MouseSlider)
	{
		MouseSlider->OnValueChanged.AddDynamic(this,&UPauseMenu::OnSliderValueChanged);
	}
	if (ContinueButton)
	{
		ContinueButton->OnClicked.AddDynamic(this,&UPauseMenu::OnClicked);
	}
}

void UPauseMenu::OnSliderValueChanged(float value)
{
	UE_LOG(LogTemp, Warning, TEXT("Slider Value Changed: %f"), value);
	if (PlayerController)
	{
		PlayerController->InputYawScale_DEPRECATED = value;
		PlayerController->InputPitchScale_DEPRECATED = -value;
	}
}

void UPauseMenu::OnClicked()
{
	UGameplayStatics::SetGamePaused(GetWorld(),false);
	this->SetVisibility(ESlateVisibility::Hidden);
	GetOwningPlayer()->SetShowMouseCursor(false);
	UE_LOG(LogTemp, Warning, TEXT("Continue"));
}

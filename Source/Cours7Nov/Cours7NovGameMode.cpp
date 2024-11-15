// Copyright Epic Games, Inc. All Rights Reserved.

#include "Cours7NovGameMode.h"
#include "Cours7NovCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACours7NovGameMode::ACours7NovGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}

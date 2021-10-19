// Copyright Epic Games, Inc. All Rights Reserved.

#include "GamePlayAbilityTestGameMode.h"
#include "GamePlayAbilityTestCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGamePlayAbilityTestGameMode::AGamePlayAbilityTestGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

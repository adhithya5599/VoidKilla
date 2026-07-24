// Copyright Epic Games, Inc. All Rights Reserved.

#include "VoidKillaGameMode.h"
#include "VoidKillaCharacter.h"
#include "UObject/ConstructorHelpers.h"

AVoidKillaGameMode::AVoidKillaGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

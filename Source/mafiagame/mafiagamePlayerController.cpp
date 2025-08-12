// Copyright Epic Games, Inc. All Rights Reserved.


#include "mafiagamePlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"
#include "mafiagameCameraManager.h"

AmafiagamePlayerController::AmafiagamePlayerController()
{
	// set the player camera manager class
	PlayerCameraManagerClass = AmafiagameCameraManager::StaticClass();
}

void AmafiagamePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Add Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
		{
			Subsystem->AddMappingContext(CurrentContext, 0);
		}
	}
}

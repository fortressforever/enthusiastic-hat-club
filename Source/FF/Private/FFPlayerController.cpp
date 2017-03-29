// Fill out your copyright notice in the Description page of Project Settings.

#include "FF.h"
#include "FFPlayerController.h"

// Called to bind functionality to input
void AFFPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	// super checks
	Super::SetupInputComponent();

	// TODO: the base ACharacter jump handling kinda stinks
	//InputComponent->BindAction("Jump", IE_Pressed, this, &AFFPlayerController::InputJump);
	//InputComponent->BindAction("Jump", IE_Released, this, &AFFPlayerController::InputStopJumping);
	InputComponent->BindAxis("Forward", this, &AFFPlayerController::Forward);
	InputComponent->BindAxis("Strafe", this, &AFFPlayerController::Strafe);
	InputComponent->BindAxis("LookX", this, &AFFPlayerController::LookX);
	InputComponent->BindAxis("LookY", this, &AFFPlayerController::LookY);

	MouseSensitivityRate = 150.0f;
}

void AFFPlayerController::Forward(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		//AddMovementInput(GetActorForwardVector(), Value);
	}
}

void AFFPlayerController::Strafe(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		//AddMovementInput(GetActorRightVector(), Value);
	}
}

void AFFPlayerController::LookX(float Rate)
{
	// calculate delta for this frame from the rate information
	//AddControllerYawInput(Rate * MouseSensitivityRate * GetWorld()->GetDeltaSeconds());
}

void AFFPlayerController::LookY(float Rate)
{
	// calculate delta for this frame from the rate information
	//AddControllerPitchInput(Rate * MouseSensitivityRate * GetWorld()->GetDeltaSeconds());
}

void AFFPlayerController::SetPawn(APawn* NewPawn)
{
	if (NewPawn == NULL)
	{
		// death cam specjump etc
	}

	AController::SetPawn(NewPawn);

	FFCharacter = Cast<AFFCharacter>(NewPawn);

	if (Player && IsLocalPlayerController())
	{
		if (GetPawn() == NULL && PlayerCameraManager != NULL)
		{
			// clear FOV incase they die zoomed etc
			FOV(ConfigFOV);
		}
		// TODO: death cam/ragdoll etc
	}
}

AFFCharacter* AFFPlayerController::GetFFCharacter()
{
	// TODO:
	return nullptr;
}

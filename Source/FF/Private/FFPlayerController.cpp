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
	InputComponent->BindAction("Jump", IE_Pressed, this, &AFFPlayerController::JumpPressed);
	InputComponent->BindAction("Jump", IE_Released, this, &AFFPlayerController::JumpReleased);
	InputComponent->BindAxis("Forward", this, &AFFPlayerController::Forward);
	InputComponent->BindAxis("Strafe", this, &AFFPlayerController::Strafe);
	InputComponent->BindAxis("LookX", this, &AFFPlayerController::LookX);
	InputComponent->BindAxis("LookY", this, &AFFPlayerController::LookY);

	MouseSensitivityRate = 150.0f;
}

// bind axis has nonconst :-(

// ReSharper disable once CppMemberFunctionMayBeConst
void AFFPlayerController::Forward(float Value)
{
	if (Value != 0.0f)
	{
		FFCharacter->MovementForwardBack(Value);
	}
}

// ReSharper disable once CppMemberFunctionMayBeConst
void AFFPlayerController::Strafe(float Value)
{
	if (Value != 0.0f)
	{
		FFCharacter->MovementStrafe(Value);
	}
}

void AFFPlayerController::LookX(float Rate)
{
	// calculate delta for this frame from the rate information
	AddYawInput(Rate * MouseSensitivityRate * GetWorld()->GetDeltaSeconds());
}

void AFFPlayerController::LookY(float Rate)
{
	// calculate delta for this frame from the rate information
	AddPitchInput(Rate * MouseSensitivityRate * GetWorld()->GetDeltaSeconds());
}

void AFFPlayerController::JumpPressed()
{
	if (FFCharacter != NULL && !IsMoveInputIgnored())
	{
		//FFCharacter->bPressedJump = true;
		FFCharacter->Jump();
	}
}

void AFFPlayerController::JumpReleased()
{
	if (FFCharacter)
	{
		//FFCharacter->bPressedJump = false;
		FFCharacter->StopJumping();
	}
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
	// for BPs
	return FFCharacter;
}


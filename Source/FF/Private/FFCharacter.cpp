// Fill out your copyright notice in the Description page of Project Settings.

#include "FF.h"
#include "FFCharacter.h"


// Sets default values
AFFCharacter::AFFCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// setup first person camera
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FFCamera"));
	CameraComponent->RelativeLocation = FVector(-39.56f, 1.75f, 64.f); 
	CameraComponent->SetupAttachment(GetCapsuleComponent());
	CameraComponent->bUsePawnControlRotation = true;

	MouseSensitivityRate = 150.0f;
}

// Called when the game starts or when spawned
void AFFCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFFCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFFCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// set up gameplay key bindings
	// super checks
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	// TODO: the base ACharacter jump handling kinda stinks
	//PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::InputJump);
	//PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::InputStopJumping);
	PlayerInputComponent->BindAxis("Forward", this, &AFFCharacter::InputForward);
	PlayerInputComponent->BindAxis("Strafe", this, &AFFCharacter::InputStrafe);
	PlayerInputComponent->BindAxis("LookX", this, &AFFCharacter::InputLookX);
	PlayerInputComponent->BindAxis("LookY", this, &AFFCharacter::InputLookY);
}

void AFFCharacter::InputForward(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void AFFCharacter::InputStrafe(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorRightVector(), Value);
	}
}
 
void AFFCharacter::InputLookX(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * MouseSensitivityRate * GetWorld()->GetDeltaSeconds());
}

void AFFCharacter::InputLookY(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * MouseSensitivityRate * GetWorld()->GetDeltaSeconds());
}
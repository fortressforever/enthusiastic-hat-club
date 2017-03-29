// Fill out your copyright notice in the Description page of Project Settings.

#include "FF.h"
#include "FFCharacter.h"


// Sets default values
AFFCharacter::AFFCharacter(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UFFCharacterMovement>(ACharacter::CharacterMovementComponentName))
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// setup first person camera
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FFCamera"));
	CameraComponent->RelativeLocation = FVector(-39.56f, 1.75f, 64.f); 
	CameraComponent->SetupAttachment(GetCapsuleComponent());
	CameraComponent->bUsePawnControlRotation = true;

	FFCharacterMovement = Cast<UFFCharacterMovement>(GetCharacterMovement());
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
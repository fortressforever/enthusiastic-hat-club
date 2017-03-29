// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "FFCharacterMovement.h"

#include "FFCharacter.generated.h"


UCLASS(config=Game)
class AFFCharacter : public ACharacter
{
	GENERATED_UCLASS_BODY()

	// FPS camera
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* CameraComponent;

	/** Cached casted FF CharacterMovement */
	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly)
	class UFFCharacterMovement* FFCharacterMovement;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Sets default values for this character's properties
	AFFCharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FORCEINLINE class UCameraComponent* GetFirstPersonCameraComponent() const { return CameraComponent; }

	// Movement commands from input
	void MovementStrafe(float Value);
	void MovementForwardBack(float Value);
};

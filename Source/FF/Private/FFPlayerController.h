// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "FFCharacter.h"
#include "FFPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class AFFPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	UPROPERTY()
	AFFCharacter* FFCharacter;
	// inputs
	void Forward(float Val);
	void Strafe(float Val);
	void LookX(float Rate);
	void LookY(float Rate);


public:
	UFUNCTION(BlueprintCallable, Category = PlayerController)
	virtual AFFCharacter* GetFFCharacter();

	// mouse sensitivity multiplier (in effective degrees / sec)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
	float MouseSensitivityRate;

	void SetupInputComponent() override;
};

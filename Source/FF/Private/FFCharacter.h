// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "FFCharacter.generated.h"

UCLASS()
class AFFCharacter : public ACharacter
{
	GENERATED_BODY()


	// FPS camera
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* CameraComponent;

public:
	// Sets default values for this character's properties
	AFFCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FORCEINLINE class UCameraComponent* GetFirstPersonCameraComponent() const { return CameraComponent; }
};

// Fill out your copyright notice in the Description page of Project Settings.

#include "FF.h"
#include "FFGameModeBase.h"

AFFGameModeBase::AFFGameModeBase() : Super()
{
	static ConstructorHelpers::FClassFinder<APawn> BaseCharacterClassFinder(TEXT("/Game/Blueprints/FFCharacterBase"));
	if (BaseCharacterClassFinder.Succeeded()) 
	{
		DefaultPawnClass = BaseCharacterClassFinder.Class;
	}
	else
	{
		DefaultPawnClass = ADefaultPawn::StaticClass();
		UE_LOG(LogTemp, Error, TEXT("Failed to find FFCharacterBase, check data blueprint exists"));
	}
}

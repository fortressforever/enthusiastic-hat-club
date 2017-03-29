// Fill out your copyright notice in the Description page of Project Settings.

#include "FF.h"
#include "FFCharacterMovement.h"


UFFCharacterMovement::UFFCharacterMovement(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// the primary purpose of this right now is to just set nicer defaults on character movements
	// have no intention to re-create all the source movements like:
	// trimping, down trimps
	// q2 style double jumps
	// rampslides and sharks
	// would rather simplify and just make the movement fast and crisp to start with,
	// which surprisingly the default networked movement can do OK at 

	MaxWalkSpeed = 1105.0f;
	AirControl = 0.65f;
	GroundFriction = 11.0f;
	BrakingFriction = 12.0f;

	JumpZVelocity = 800.0f;

	MaxAcceleration = 3500.0f;

	// verdict is out on this one
	NetworkSmoothingMode = ENetworkSmoothingMode::Exponential;
}
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
	// which surprisingly the default networked movement can do OK at .
	// if someone was so inclined to do so, this class would be the place to do it as it can handle
	// the frame by frame movement calculations and pmove

	MaxWalkSpeed = 1000.0f;
	AirControl = 0.75f;
	GroundFriction = 4.0f;
	BrakingFriction = 10.0f;
	BrakingFrictionFactor = 3;
	GravityScale = 1.0f;
	JumpZVelocity = 350.0f;
	BrakingDecelerationFalling = 1.0f;

	Mass = 110.0f;
	// todo: non-accel based strafe movement etc
	MaxAcceleration = 6500.0f;

	// verdict is out on this one
	NetworkSmoothingMode = ENetworkSmoothingMode::Exponential;
}

bool UFFCharacterMovement::DoJump(bool bReplayingMoves)
{ 
	if (CharacterOwner && CharacterOwner->CanJump())
	{
		// Don't jump if we can't move up/down.
		if (!bConstrainToPlane || FMath::Abs(PlaneConstraintNormal.Z) != 1.f)
		{
			Velocity.Z = JumpZVelocity;
			SetMovementMode(MOVE_Falling);
			return true;
		}
	}

	return false;
}
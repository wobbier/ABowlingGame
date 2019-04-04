#pragma once
#include <DirectXMath.h>
#include "Game.h"
#include "Cores/FlyingCameraCore.h"
#include "Cores/PinSpotterCore.h"

class ABowlingGame
	: public Game
{
public:
	ABowlingGame();
	virtual ~ABowlingGame() override;

	virtual void Initialize() override;

	virtual void Update(float DeltaTime) override;

	virtual void End() override;

	FlyingCameraCore* FlyingCameraController;
	PinSpotterCore* PinSpotter;

	WeakPtr<Entity> MainCamera;
	WeakPtr<Entity> SecondaryCamera;
	WeakPtr<Entity> TestModel;
	WeakPtr<Entity> BowlingBall;
};

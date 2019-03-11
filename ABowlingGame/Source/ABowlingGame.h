#pragma once
#include <DirectXMath.h>
#include "Game.h"
#include <glm.hpp>
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

	Entity MainCamera;
	Entity SecondaryCamera;
	Entity TestModel;
};

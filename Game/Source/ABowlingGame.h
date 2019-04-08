#pragma once
#include <DirectXMath.h>
#include "Game.h"
#include "Cores/PinSpotterCore.h"

class ABowlingGame
	: public Game
{
public:
	ABowlingGame();
	virtual ~ABowlingGame() override;

	virtual void OnInitialize() override;

	virtual void OnStart() override;
	virtual void OnUpdate(float DeltaTime) override;
	virtual void OnEnd() override;

	PinSpotterCore* PinSpotter;

	WeakPtr<Entity> MainCamera;
	WeakPtr<Entity> SecondaryCamera;
	WeakPtr<Entity> TestModel;
	WeakPtr<Entity> BowlingBall;
};

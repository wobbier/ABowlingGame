#pragma once
#include <DirectXMath.h>
#include "Game.h"
#include "Cores/PinSpotterCore.h"

class ABowlingGame final
	: public Game
{
public:
	ABowlingGame();
	~ABowlingGame();

	virtual void OnInitialize() final;

	virtual void OnStart() final;
	virtual void OnUpdate(float DeltaTime) final;
	virtual void PostRender() final;
	virtual void OnEnd() final;

	PinSpotterCore* PinSpotter;

	WeakPtr<Entity> MainCamera;
	WeakPtr<Entity> SecondaryCamera;
	WeakPtr<Entity> TestModel;
	WeakPtr<Entity> BowlingBall;
};

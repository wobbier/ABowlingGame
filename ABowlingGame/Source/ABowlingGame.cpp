#include "ABowlingGame.h"
#include "ECS/Component.h"
#include "Engine/Clock.h"
#include "Components/Transform.h"
#include "ECS/Entity.h"
#include <string>
#include "Engine/Input.h"
#include "Components/Animation.h"
#include "Components/Camera.h"
#include "Components/Physics/Rigidbody.h"
#include "Components/Graphics/Model.h"
#include "Components/Lighting/Light.h"
#include "Components/FlyingCamera.h"

#include <memory>
#include "Engine/World.h"
#include "FilePath.h"

ABowlingGame::ABowlingGame()
	: Game()
{
}

ABowlingGame::~ABowlingGame()
{
	Game::~Game();
}

void ABowlingGame::Initialize()
{
	auto GameWorld = GetEngine().GetWorld().lock();

	MainCamera = GameWorld->CreateEntity();
	Transform& CameraPos = MainCamera.AddComponent<Transform>("Main Camera");
	CameraPos.SetPosition(glm::vec3(0, 5, 20));
	MainCamera.AddComponent<Camera>();
	MainCamera.AddComponent<FlyingCamera>();
	MainCamera.AddComponent<Light>();

	SecondaryCamera = GameWorld->CreateEntity();
	Transform& SecondaryPos = SecondaryCamera.AddComponent<Transform>("Secondary Camera");
	SecondaryPos.SetPosition(glm::vec3(0, 5, 20));
	SecondaryCamera.AddComponent<Camera>();
	SecondaryCamera.AddComponent<Light>();
	SecondaryCamera.AddComponent<FlyingCamera>();
	SecondaryCamera.AddComponent<Model>("Assets/marcus.fbx");

	PinSpotter = new PinSpotterCore(6);
	GameWorld->AddCore<PinSpotterCore>(*PinSpotter);

	FlyingCameraController = new FlyingCameraCore();
	GameWorld->AddCore<FlyingCameraCore>(*FlyingCameraController);
}

void ABowlingGame::Update(float DeltaTime)
{
	FlyingCameraController->Update(DeltaTime);
	PinSpotter->Update(DeltaTime);

	Input& Instance = Input::GetInstance();
	if (Instance.IsKeyDown(KeyCode::Number1))
	{
		MainCamera.GetComponent<Camera>().SetCurrent();
		//TestModel.GetComponent<Transform>().SetPosition(glm::vec3(0, 20, 0));
	}
	if (Instance.IsKeyDown(KeyCode::Number2))
	{
		SecondaryCamera.GetComponent<Camera>().SetCurrent();
	}
}

void ABowlingGame::End()
{
}
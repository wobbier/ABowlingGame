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
#include "Math/Vector3.h"

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
	CameraPos.SetPosition(Vector3(0, 5, 20));
	MainCamera.AddComponent<Camera>();
	MainCamera.AddComponent<FlyingCamera>();
	MainCamera.AddComponent<Light>();

	SecondaryCamera = GameWorld->CreateEntity();
	Transform& SecondaryPos = SecondaryCamera.AddComponent<Transform>("Secondary Camera");
	SecondaryPos.SetPosition(Vector3(0, 5, 20));
	SecondaryCamera.AddComponent<Camera>();
	SecondaryCamera.AddComponent<Light>();
	SecondaryCamera.AddComponent<FlyingCamera>();
	//SecondaryCamera.AddComponent<Model>("Assets/marcus.fbx");

	BowlingBall = GameWorld->CreateEntity();
	Transform& ballTransform = BowlingBall.AddComponent<Transform>("BowlingBall");
	ballTransform.SetScale(0.1f);
	BowlingBall.AddComponent<Model>("Assets/Models/BowlingBall.fbx");
	BowlingBall.AddComponent<Rigidbody>();

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
	}
	if (Instance.IsKeyDown(KeyCode::Number2))
	{
		SecondaryCamera.GetComponent<Camera>().SetCurrent();
	}

	if (Input::GetInstance().IsKeyDown(KeyCode::LeftButton))
	{
		Transform& transform = BowlingBall.GetComponent<Transform>();
		transform.SetPosition(MainCamera.GetComponent<Transform>().GetPosition());
		BowlingBall.GetComponent<Rigidbody>().ApplyForce(Camera::CurrentCamera->Front, 500);
	}
}

void ABowlingGame::End()
{
}
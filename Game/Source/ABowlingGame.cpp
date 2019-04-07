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
	PinSpotter = new PinSpotterCore(6);
	FlyingCameraController = new FlyingCameraCore();
}

ABowlingGame::~ABowlingGame()
{
	Game::~Game();
}

void ABowlingGame::Initialize()
{
	auto GameWorld = GetEngine().GetWorld().lock();

	//MainCamera = GameWorld->CreateEntity();
	//Transform& CameraPos = MainCamera.lock()->AddComponent<Transform>("Main Camera");
	//CameraPos.SetPosition(Vector3(0, 5, 20));
	//MainCamera.lock()->AddComponent<Camera>().SetCurrent();
	//MainCamera.lock()->AddComponent<FlyingCamera>();
	//MainCamera.lock()->AddComponent<Light>();

	//SecondaryCamera = GameWorld->CreateEntity();
	//Transform& SecondaryPos = SecondaryCamera.lock()->AddComponent<Transform>("Secondary Camera");
	//SecondaryPos.SetPosition(Vector3(0, 5, 20));
	//SecondaryCamera.lock()->AddComponent<Camera>();
	//SecondaryCamera.lock()->AddComponent<Light>();
	//SecondaryCamera.lock()->AddComponent<FlyingCamera>();
	////SecondaryCamera.AddComponent<Model>("Assets/marcus.fbx");

	//BowlingBall = GameWorld->CreateEntity();
	//Transform& ballTransform = BowlingBall.lock()->AddComponent<Transform>("BowlingBall");
	//ballTransform.SetScale(0.1f);
	//BowlingBall.lock()->AddComponent<Model>("Assets/Models/BowlingBall.fbx");
	//BowlingBall.lock()->AddComponent<Rigidbody>();

	//GameWorld->AddCore<PinSpotterCore>(*PinSpotter);

	//GameWorld->AddCore<FlyingCameraCore>(*FlyingCameraController);
}

void ABowlingGame::Update(float DeltaTime)
{
	FlyingCameraController->Update(DeltaTime);
	PinSpotter->Update(DeltaTime);

	Input& Instance = Input::GetInstance();
	if (Instance.IsKeyDown(KeyCode::Number1))
	{
		//MainCamera.lock()->GetComponent<Camera>().SetCurrent();
	}
	if (Instance.IsKeyDown(KeyCode::Number2))
	{
		//SecondaryCamera.lock()->GetComponent<Camera>().SetCurrent();
	}

	if (Input::GetInstance().IsKeyDown(KeyCode::LeftButton))
	{
		//Transform& transform = BowlingBall.lock()->GetComponent<Transform>();
		//transform.SetPosition(MainCamera.lock()->GetComponent<Transform>().GetPosition());
		//BowlingBall.lock()->GetComponent<Rigidbody>().ApplyForce(Camera::CurrentCamera->Front, 500);
	}
}

void ABowlingGame::End()
{
}
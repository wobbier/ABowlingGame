#pragma once

#include "ECS/Core.h"
#include "Components/Physics/Rigidbody.h"
#include "Components/Pin.h"
#include "Components/Transform.h"
#include "Components/Graphics/Model.h"
#include "Engine/Input.h"
#include <string>

class PinSpotterCore
	: public Core<PinSpotterCore>
{
public:
	PinSpotterCore(int InitialAmountOfPins)
		: Core(ComponentFilter().Requires<Rigidbody>().Requires<Transform>())
		, PinsToSpawn(InitialAmountOfPins)
	{
		Pins.reserve(PinsToSpawn);
	}

	virtual void Init() final
	{
		for (int i = 0; i < PinsToSpawn; ++i)
		{
			Entity pin = GetWorld().CreateEntity();
			std::string name("Pin");
			Transform& transform = pin.AddComponent<Transform>(name);
			transform.SetPosition(Vector3(0, 20, 0));
			transform.SetScale(Vector3(0.2f, 0.2f, 0.2f));
			//transform.SetRotation(glm::vec3(-90, 0, 0));
			pin.AddComponent<Rigidbody>();
			pin.AddComponent<Model>("Assets/Pin.fbx");
			Pins.push_back(std::move(pin));
		}
	}

	virtual void Update(float dt) final
	{
		auto& Pins = GetEntities();

		for (const Entity& pin : Pins)
		{
			Transform& TransformComponent = pin.GetComponent<Transform>();

			if (Input::GetInstance().IsKeyDown(KeyCode::B))
			{
				TransformComponent.Translate(Vector3(0.f, -1.0f * dt, 0.f));
			}
			if (Input::GetInstance().IsKeyDown(KeyCode::N))
			{
				TransformComponent.Translate(Vector3(1.0f * dt, 0.f, 0.f));
			}
		}
	}
private:
	unsigned int PinsToSpawn = 1;
	std::vector<Entity> Pins;
};
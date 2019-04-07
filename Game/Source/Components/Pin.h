#pragma once

#include "ECS/Component.h"
#include "ECS/ComponentDetail.h"

class Pin
	: public Component<Pin>
{
public:
	Pin()
	: Component<Pin>()
	{
	}

	virtual void Init() final
	{

	}
};
ME_REGISTER_COMPONENT(Pin)
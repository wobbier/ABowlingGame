#include "ABowlingGame.h"
#include "Engine/Engine.h"

int main()
{
	GetEngine().Init(new ABowlingGame());
	GetEngine().Run();

	return 0;
}
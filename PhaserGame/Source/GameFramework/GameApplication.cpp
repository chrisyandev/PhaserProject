#include "GameFramework/GameApplication.h"
#include "Framework/World.h"

ph::Application* GetApplication()
{
	return new ph::GameApplication{};
}

namespace ph
{
	GameApplication::GameApplication()
	{
		LoadWorld<World>();
	}
}
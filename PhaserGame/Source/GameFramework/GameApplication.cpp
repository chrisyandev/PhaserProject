#include "GameFramework/GameApplication.h"
#include "Framework/World.h"
#include "Framework/Actor.h"

ph::Application* GetApplication()
{
	return new ph::GameApplication{};
}

namespace ph
{
	GameApplication::GameApplication()
	{
		TWeakPtr<World> newWorld = loadWorld<World>();
		newWorld.lock()->SpawnActor<Actor>();
		newWorld.lock()->SpawnActor<Actor>();
		newWorld.lock()->SpawnActor<Actor>();
	}
}
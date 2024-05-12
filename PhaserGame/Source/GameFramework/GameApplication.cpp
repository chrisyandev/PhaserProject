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
		m_actorToDestroy = newWorld.lock()->SpawnActor<Actor>();
		m_counter = 0;
	}

	void GameApplication::tick(float deltaTime)
	{
		m_counter += deltaTime;
		if (m_counter > 2.f)
		{
			if (!m_actorToDestroy.expired())
			{
				m_actorToDestroy.lock()->destroy();
			}
		}
	}
}
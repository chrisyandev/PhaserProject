#include "Framework/World.h"
#include "Framework/Core.h"
#include "Framework/Actor.h"

namespace ph
{
	World::World(Application* owningApp)
		: m_owningApp{ owningApp },
		m_bBegunPlay(false),
		m_actors{},
		m_pendingActors{}
	{
	}

	World::~World()
	{
	}

	void World::beginPlayInternal()
	{
		if (!m_bBegunPlay)
		{
			m_bBegunPlay = true;
			beginPlay();
		}
	}

	void World::tickInternal(float deltaTime)
	{
		for (TSharedPtr<Actor> actor : m_pendingActors)
		{
			m_actors.push_back(actor);
			actor->beginPlayInternal();
		}

		m_pendingActors.clear();
		
		for (TSharedPtr<Actor> actor : m_actors)
		{
			actor->tick(deltaTime);
		}

		tick(deltaTime);
	}

	void World::beginPlay()
	{
		LOG("Begin Play");
	}

	void World::tick(float deltaTime)
	{
		LOG("%f", 1.f / deltaTime);
	}
}

#include "Framework/World.h"
#include "Framework/Core.h"

namespace ph
{
	World::World(Application* owningApp)
		: m_owningApp{ owningApp },
		m_bBegunPlay(false)
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

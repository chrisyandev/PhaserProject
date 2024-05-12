#include "Framework/Actor.h"
#include "Framework/Core.h"

namespace ph
{
	Actor::Actor(World* owningWorld)
		: m_owningWorld{ owningWorld },
		m_bBegunPlay{ false }
	{
	}

	Actor::~Actor()
	{
	}

	void Actor::beginPlayInternal()
	{
		if (!m_bBegunPlay)
		{
			m_bBegunPlay = true;
			beginPlay();
		}
	}

	void Actor::beginPlay()
	{
		LOG("Actor Begin Play");
	}

	void Actor::tick(float deltaTime)
	{
		LOG("Actor Tick");
	}
}
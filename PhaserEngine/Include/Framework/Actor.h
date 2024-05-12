#pragma once
#include "Framework/Object.h"

namespace ph
{
	class World;

	class Actor : public Object
	{
	public:
		Actor(World* owningWorld);
		virtual ~Actor();
		void beginPlayInternal();
		virtual void beginPlay();
		virtual void tick(float deltaTime);

	private:
		World* m_owningWorld;
		bool m_bBegunPlay;
	};
}
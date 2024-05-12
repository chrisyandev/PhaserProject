#pragma once

namespace ph
{
	class World;

	class Actor
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
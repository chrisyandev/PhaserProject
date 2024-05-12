#pragma once
#include <Framework/Application.h>
#include <Framework/Core.h>

namespace ph
{
	class Actor;

	class GameApplication : public Application
	{
	public:
		GameApplication();
		virtual void tick(float deltaTime) override;

	private:
		float m_counter;
		TWeakPtr<Actor> m_actorToDestroy;
	};
}
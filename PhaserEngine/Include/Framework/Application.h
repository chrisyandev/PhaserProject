#pragma once
#include <SFML/Graphics.hpp>
#include "Framework/Core.h"

namespace ph
{
	class World;

	class Application
	{
	public:
		Application();
		void run();
		
		template<typename WorldType>
		TWeakPtr<WorldType> LoadWorld()
		{
			TSharedPtr<WorldType> newWorld{ new WorldType{this} };
			currentWorld = newWorld;
			return newWorld;
		}

	private:
		void tickInternal(float deltaTime);
		virtual void tick(float deltaTime);
		void renderInternal();
		virtual void render();
		sf::RenderWindow m_window;
		float m_targetFrameRate;
		sf::Clock m_tickClock;
		TSharedPtr<World> currentWorld;
	};
}
#pragma once
#include <SFML/Graphics.hpp>
#include "Framework/Core.h"

namespace ph
{
	class World;

	class Application
	{
	public:
		Application(unsigned int windowWidth,
			        unsigned int windowHeight,
			        const std::string& title,
			        sf::Uint32 style);
		void run();

		template<typename WorldType>
		TWeakPtr<WorldType> loadWorld()
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
#pragma once
#include <SFML/Graphics.hpp>

namespace ph
{
	class Application
	{
	public:
		Application();
		void run();

	private:
		void tick(float deltaTime);
		void render();
		sf::RenderWindow m_window;
		float m_targetFrameRate;
		sf::Clock m_tickClock;
	};
}
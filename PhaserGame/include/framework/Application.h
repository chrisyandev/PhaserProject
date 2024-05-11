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
		void tickInternal(float deltaTime);
		virtual void tick(float deltaTime);
		
		void renderInternal();
		virtual void render();

		sf::RenderWindow m_window;
		float m_targetFrameRate;
		sf::Clock m_tickClock;
	};
}
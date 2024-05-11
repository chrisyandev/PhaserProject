#include <iostream>
#include "framework/Application.h"

namespace ph
{
	Application::Application()
		: m_window{ sf::VideoMode(600, 980), "Phaser" },
		m_targetFrameRate{ 60.f },
		m_tickClock{}
	{
	}

	void Application::run()
	{
		m_tickClock.restart();
		float accumulatedTime = 0.f;
		float targetDeltaTime = 1.f / m_targetFrameRate;
		while (m_window.isOpen())
		{
			sf::Event windowEvent;
			while (m_window.pollEvent(windowEvent))
			{
				if (windowEvent.type == sf::Event::EventType::Closed)
				{
					m_window.close();
				}
			}

			accumulatedTime += m_tickClock.restart().asSeconds();
			while (accumulatedTime > targetDeltaTime)
			{
				accumulatedTime -= targetDeltaTime;
				tick(targetDeltaTime);
				render();
			}
		}
	}

	void Application::tick(float deltaTime)
	{
		std::cout << 1.f / deltaTime << std::endl;
	}

	void Application::render()
	{

	}
}

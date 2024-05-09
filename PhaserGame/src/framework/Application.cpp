#include "framework/Application.h"

namespace ph
{
	Application::Application()
		: m_window{ sf::VideoMode(600, 980), "Phaser" }
	{
	}

	void Application::Run()
	{
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
		}
	}
}

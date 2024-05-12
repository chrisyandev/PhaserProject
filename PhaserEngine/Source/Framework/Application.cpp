#include "Framework/Application.h"
#include "Framework/Core.h"
#include "Framework/World.h"

namespace ph
{
	Application::Application()
		: m_window{ sf::VideoMode(600, 980), "Phaser" },
		m_targetFrameRate{ 60.f },
		m_tickClock{},
		currentWorld(nullptr)
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
			float frameDeltaTime = m_tickClock.restart().asSeconds();
			accumulatedTime += frameDeltaTime;
			while (accumulatedTime > targetDeltaTime)
			{
				accumulatedTime -= targetDeltaTime;
				tickInternal(targetDeltaTime);
				renderInternal();
			}
		}
	}

	void Application::tickInternal(float deltaTime)
	{
		tick(deltaTime);
		
		if (currentWorld)
		{
			currentWorld->beginPlayInternal();
			currentWorld->tickInternal(deltaTime);
		}
	}

	void Application::renderInternal()
	{
		m_window.clear();

		render();

		m_window.display();
	}

	void Application::render()
	{
		sf::RectangleShape rect{ sf::Vector2f(100,100) };
		rect.setFillColor(sf::Color::Green);
		rect.setOrigin(50, 50);
		rect.setPosition(m_window.getSize().x / 2.f, m_window.getSize().y / 2.f);
		m_window.draw(rect);
	}

	void Application::tick(float deltaTime)
	{
	}
}

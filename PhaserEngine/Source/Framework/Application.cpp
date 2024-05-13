#include "Framework/Application.h"
#include "Framework/Core.h"
#include "Framework/World.h"

namespace ph
{
    Application::Application(unsigned int windowWidth,
                             unsigned int windowHeight,
                             const std::string& title,
                             sf::Uint32 style)
        : m_window{ sf::VideoMode(windowWidth, windowHeight), title, style }
        , m_targetFrameRate{ 60.f }
        , m_tickClock{}
        , currentWorld{ nullptr }
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
        if (currentWorld)
        {
            currentWorld->render(m_window);
        }
    }

    void Application::tick(float deltaTime)
    {
    }
}

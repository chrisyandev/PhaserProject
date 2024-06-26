#include "Framework/Application.h"
#include "Framework/Core.h"
#include "Framework/World.h"
#include "Framework/AssetManager.h"
#include "Framework/PhysicsSystem.h"

namespace ph
{
    Application::Application(unsigned int windowWidth,
                             unsigned int windowHeight,
                             const std::string& title,
                             sf::Uint32 style)
        : m_window{ sf::VideoMode{ windowWidth, windowHeight }, title, style }
        , m_targetFrameRate{ 60.f }
        , m_tickClock{}
        , m_currentWorld{ nullptr }
        , m_cleanUpClock{}
        , m_cleanUpInterval{ 2.f }
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

    sf::Vector2f Application::getWindowSize() const
    {
        return static_cast<sf::Vector2f>(m_window.getSize());
    }

    void Application::tickInternal(float deltaTime)
    {
        tick(deltaTime);

        if (m_currentWorld)
        {
            m_currentWorld->beginPlayInternal();
            m_currentWorld->tickInternal(deltaTime);
        }

        PhysicsSystem::get().step(deltaTime);

        if (m_cleanUpClock.getElapsedTime().asSeconds() >= m_cleanUpInterval)
        {
            m_cleanUpClock.restart();
            AssetManager::get().cleanUp();
            if (m_currentWorld)
            {
                m_currentWorld->cleanUp();
            }
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
        if (m_currentWorld)
        {
            m_currentWorld->render(m_window);
        }
    }

    void Application::tick(float deltaTime)
    {
    }
}

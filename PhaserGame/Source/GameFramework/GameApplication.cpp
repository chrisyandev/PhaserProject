#include "GameFramework/GameApplication.h"
#include "Config.h"
#include "Framework/AssetManager.h"
#include "Framework/World.h"
#include "Framework/Actor.h"
#include "Spaceship/Spaceship.h"
#include "Player/PlayerSpaceship.h"
#include "Framework/MathUtility.h"

ph::Application* GetApplication()
{
    return new ph::GameApplication{};
}

namespace ph
{
    GameApplication::GameApplication()
        : Application{ 980, 600, "Phaser", sf::Style::Titlebar | sf::Style::Close }
        , m_counter{ 0.f }
    {
        AssetManager::get().setRootDirectory(getResourceDirectory());

        TWeakPtr<World> newWorld = loadWorld<World>();

        m_testPlayerSpaceship = newWorld.lock()->spawnActor<PlayerSpaceship>();
        m_testPlayerSpaceship.lock()->setTexture("PNG/playerShip2_orange.png");
        m_testPlayerSpaceship.lock()->setActorLocation(0.5f * getWindowSize());
        m_testPlayerSpaceship.lock()->setActorRotation(-90.f);

        TWeakPtr<Spaceship> testSpaceship = newWorld.lock()->spawnActor<Spaceship>();
        testSpaceship.lock()->setTexture("PNG/playerShip2_green.png");
        testSpaceship.lock()->setActorLocation(sf::Vector2f{ 100.f, 50.f });
    }

    void GameApplication::tick(float deltaTime)
    {
        m_counter += deltaTime;
        if (m_counter > 5.f)
        {
            if (!m_testPlayerSpaceship.expired())
            {
                m_testPlayerSpaceship.lock()->destroy();
            }
        }
    }
}
#include "GameFramework/GameApplication.h"
#include "Config.h"
#include "Framework/AssetManager.h"
#include "Framework/World.h"
#include "Framework/Actor.h"
#include "Player/PlayerSpaceship.h"

ph::Application* GetApplication()
{
    return new ph::GameApplication{};
}

namespace ph
{
    GameApplication::GameApplication()
        : Application{ 980, 600, "Phaser", sf::Style::Titlebar | sf::Style::Close }
    {
        AssetManager::get().setRootDirectory(getResourceDirectory());

        TWeakPtr<World> newWorld = loadWorld<World>();
        newWorld.lock()->spawnActor<Actor>();

        m_testPlayerSpaceship = newWorld.lock()->spawnActor<PlayerSpaceship>();
        m_testPlayerSpaceship.lock()->setTexture("PNG/playerShip2_orange.png");
        m_testPlayerSpaceship.lock()->setActorLocation(sf::Vector2f(490.f, 300.f));
        m_testPlayerSpaceship.lock()->setActorRotation(-90.f);
        m_testPlayerSpaceship.lock()->setVelocity(sf::Vector2f(0.f, -200.f));

        m_counter = 0;
    }

    void GameApplication::tick(float deltaTime)
    {
    }
}
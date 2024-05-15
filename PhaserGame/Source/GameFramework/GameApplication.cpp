#include "GameFramework/GameApplication.h"
#include "Framework/World.h"
#include "Framework/Actor.h"
#include "Config.h"

ph::Application* GetApplication()
{
    return new ph::GameApplication{};
}

namespace ph
{
    GameApplication::GameApplication()
        : Application{ 980, 600, "Phaser", sf::Style::Titlebar | sf::Style::Close }
    {
        TWeakPtr<World> newWorld = loadWorld<World>();
        newWorld.lock()->spawnActor<Actor>();
        m_actorToDestroy = newWorld.lock()->spawnActor<Actor>();
        m_actorToDestroy.lock()->setTexture(GetResourceDir() + "PNG/playerShip2_orange.png");
        m_actorToDestroy.lock()->setActorLocation(sf::Vector2f(490.f, 300.f));
        m_counter = 0;
    }

    void GameApplication::tick(float deltaTime)
    {
        if (!m_actorToDestroy.expired())
        {
            m_actorToDestroy.lock()->addActorRotationOffset(30.f * deltaTime);
        }

        m_counter += deltaTime;
        if (m_counter > 2.f)
        {
            if (!m_actorToDestroy.expired())
            {
                m_actorToDestroy.lock()->destroy();
            }
        }
    }
}
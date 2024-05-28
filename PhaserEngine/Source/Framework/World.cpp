#include "Framework/World.h"
#include "Framework/Core.h"
#include "Framework/Actor.h"
#include "Framework/Application.h"

namespace ph
{
    World::World(Application* owningApp)
        : m_owningApp{ owningApp }
        , m_bBegunPlay(false)
        , m_actors{}
        , m_pendingActors{}
    {
    }

    World::~World()
    {
    }

    void World::beginPlayInternal()
    {
        if (!m_bBegunPlay)
        {
            m_bBegunPlay = true;
            beginPlay();
        }
    }

    void World::tickInternal(float deltaTime)
    {
        for (TSharedPtr<Actor> actor : m_pendingActors)
        {
            m_actors.push_back(actor);
            actor->beginPlayInternal();
        }

        m_pendingActors.clear();

        for (auto itr = m_actors.begin(); itr != m_actors.end();)
        {
            itr->get()->tickInternal(deltaTime);
            ++itr;
        }

        tick(deltaTime);
    }

    void World::render(sf::RenderWindow& window)
    {
        for (auto& actor : m_actors)
        {
            actor->render(window);
        }
    }

    sf::Vector2f World::getWindowSize() const
    {
        return m_owningApp->getWindowSize();
    }

    void World::cleanUp()
    {
        for (auto itr = m_actors.begin(); itr != m_actors.end();)
        {
            if (itr->get()->isPendingDestroy())
            {
                itr = m_actors.erase(itr);
            }
            else
            {
                ++itr;
            }
        }
    }

    void World::beginPlay()
    {
    }

    void World::tick(float deltaTime)
    {
    }
}

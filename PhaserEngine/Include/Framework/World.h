#pragma once
#include <SFML/Graphics.hpp>
#include "Framework/Core.h"

namespace ph
{
    class Application;
    class Actor;

    class World
    {
    public:
        World(Application* owningApp);
        virtual ~World();
        void beginPlayInternal();
        void tickInternal(float deltaTime);
        void render(sf::RenderWindow& window);
        sf::Vector2f getWindowSize() const;
        void cleanUp();

        template<typename ActorType, typename... Ts>
        TWeakPtr<ActorType> spawnActor(Ts... args)
        {
            TSharedPtr<ActorType> newActor{ new ActorType{ this, args... } };
            m_pendingActorsToAdd.push_back(newActor);
            return newActor;
        }

    private:
        void beginPlay();
        void tick(float deltaTime);
        Application* m_owningApp;
        bool m_bBegunPlay;
        TArray<TSharedPtr<Actor>> m_actors;
        TArray<TSharedPtr<Actor>> m_pendingActorsToAdd;
    };
}
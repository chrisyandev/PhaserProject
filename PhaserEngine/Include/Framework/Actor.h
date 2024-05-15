#pragma once
#include <SFML/Graphics.hpp>
#include "Framework/Core.h"
#include "Framework/Object.h"

namespace ph
{
    class World;

    class Actor : public Object
    {
    public:
        Actor(World* owningWorld, const std::string& texturePath = "");
        virtual ~Actor();
        void beginPlayInternal();
        virtual void beginPlay();
        void tickInternal(float deltaTime);
        virtual void tick(float deltaTime);
        void setTexture(const std::string& texturePath);
        void render(sf::RenderWindow& window);
        sf::Vector2f getActorLocation() const;
        float getActorRotation() const;
        void setActorLocation(const sf::Vector2f& newLocation);
        void setActorRotation(float newRotation);
        void addActorLocationOffset(const sf::Vector2f& offsetAmount);
        void addActorRotationOffset(float offsetAmount);
        sf::Vector2f getActorForwardVector();
        sf::Vector2f getActorRightVector();

    private:
        void centerPivot();
        World* m_owningWorld;
        bool m_bBegunPlay;
        sf::Sprite m_sprite;
        TSharedPtr<sf::Texture> m_texture;
    };
}
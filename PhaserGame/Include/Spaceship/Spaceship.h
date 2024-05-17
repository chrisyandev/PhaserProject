#pragma once
#include "Framework/Actor.h"

namespace ph
{
    class Spaceship : public Actor
    {
    public:
        Spaceship(World* owningWorld, const std::string& texturePath = "");
        virtual void tick(float deltaTime) override;
        void setVelocity(const sf::Vector2f& newVelocity);
        sf::Vector2f getVelocity() const { return m_velocity; }
        virtual void shoot();

    private:
        sf::Vector2f m_velocity;
    };
}
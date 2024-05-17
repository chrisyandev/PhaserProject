#include "Spaceship/Spaceship.h"

namespace ph
{
    Spaceship::Spaceship(World* owningWorld, const std::string& texturePath)
        : Actor{ owningWorld, texturePath }
        , m_velocity{}
    {
    }

    void Spaceship::tick(float deltaTime)
    {
        Actor::tick(deltaTime);

        addActorLocationOffset(getVelocity() * deltaTime);
    }

    void Spaceship::setVelocity(const sf::Vector2f& newVelocity)
    {
        m_velocity = newVelocity;
    }

    void Spaceship::shoot()
    {
    }
}
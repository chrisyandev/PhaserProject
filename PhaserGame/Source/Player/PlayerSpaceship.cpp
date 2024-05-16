#include "Player/PlayerSpaceship.h"
#include "SFML/System.hpp"
#include "Framework/MathUtility.h"

namespace ph
{
    PlayerSpaceship::PlayerSpaceship(World* owningWorld, const std::string& texturePath)
        : Spaceship{ owningWorld, texturePath }
        , m_movementInput{}
        , m_movementSpeed{ 20000.f }
    {
    }

    void PlayerSpaceship::tick(float deltaTime)
    {
        Spaceship::tick(deltaTime);

        handleInput(deltaTime);
        clampActorLocation();
    }

    void PlayerSpaceship::handleInput(float deltaTime)
    {
        m_movementInput.x = m_movementInput.y = 0.f;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            m_movementInput.x -= 1.f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            m_movementInput.x += 1.f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            m_movementInput.y -= 1.f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            m_movementInput.y += 1.f;
        }

        normalizeMovement();
        setVelocity(m_movementInput * m_movementSpeed * deltaTime);
    }

    void PlayerSpaceship::normalizeMovement()
    {
        normalize(m_movementInput);
    }

    void PlayerSpaceship::clampActorLocation()
    {
        sf::Vector2f actorLocation = getActorLocation();
        sf::Vector2u windowSize = getWindowSize();
        actorLocation.x = actorLocation.x < 0.f ? 0.f : actorLocation.x;
        actorLocation.x = actorLocation.x > windowSize.x ? windowSize.x : actorLocation.x;
        actorLocation.y = actorLocation.y < 0.f ? 0.f : actorLocation.y;
        actorLocation.y = actorLocation.y > windowSize.y ? windowSize.y : actorLocation.y;
        setActorLocation(actorLocation);
    }
}
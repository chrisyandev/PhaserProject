#include "Player/PlayerSpaceship.h"
#include "SFML/System.hpp"
#include "Framework/MathUtility.h"
#include "Weapon/BulletShooter.h"

namespace ph
{
    PlayerSpaceship::PlayerSpaceship(World* owningWorld, const std::string& texturePath)
        : Spaceship{ owningWorld, texturePath }
        , m_movementInput{}
        , m_movementSpeed{ 500.f }
        , m_bulletShooter{ new BulletShooter{ this, 0.5f } }
    {
    }

    void PlayerSpaceship::tick(float deltaTime)
    {
        Spaceship::tick(deltaTime);

        handleInput(deltaTime);
        clampActorLocation();
    }

    void PlayerSpaceship::shoot()
    {
        Spaceship::shoot();

        if (m_bulletShooter)
        {
            m_bulletShooter->shoot();
        }
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
        setVelocity(m_movementInput * m_movementSpeed);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            shoot();
        }
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
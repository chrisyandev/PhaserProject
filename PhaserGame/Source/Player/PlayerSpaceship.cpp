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

        normalizeInput();
        setVelocity(m_movementInput * m_movementSpeed * deltaTime);
    }

    void PlayerSpaceship::normalizeInput()
    {
        normalize(m_movementInput);
    }
}
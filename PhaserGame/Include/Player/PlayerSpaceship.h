#pragma once
#include "Spaceship/Spaceship.h"

namespace ph
{
    class BulletShooter;

    class PlayerSpaceship : public Spaceship
    {
    public:
        PlayerSpaceship(World* owningWorld, const std::string& texturePath = "PNG/playerShip1_green.png");
        virtual void tick(float deltaTime) override;
        float getMovementSpeed() const { return m_movementSpeed; }
        void setMovementSpeed(float newSpeed) { m_movementSpeed = newSpeed; }
        virtual void shoot() override;

    private:
        void handleInput(float deltaTime);
        void normalizeMovement();
        void clampActorLocation();
        sf::Vector2f m_movementInput;
        float m_movementSpeed;
        TUniquePtr<BulletShooter> m_bulletShooter;
    };
}
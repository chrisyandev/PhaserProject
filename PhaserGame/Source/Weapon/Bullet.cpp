#include "Weapon/Bullet.h"

namespace ph
{
    Bullet::Bullet(World* owningWorld,
                   Actor* owningActor,
                   const std::string& texturePath,
                   float speed,
                   float damage)
        : Actor{ owningWorld, texturePath }
        , m_owningActor{ owningActor }
        , m_speed{ speed }
        , m_damage{ damage }
    {
    }

    void Bullet::tick(float deltaTime)
    {
        Actor::tick(deltaTime);
        
        move(deltaTime);
    }

    void Bullet::setSpeed(float newSpeed)
    {
        m_speed = newSpeed;
    }

    void Bullet::setDamage(float newDamage)
    {
        m_damage = newDamage;
    }

    void Bullet::move(float deltaTime)
    {
        addActorLocationOffset(getActorForwardVector() * m_speed * deltaTime);
    }
}
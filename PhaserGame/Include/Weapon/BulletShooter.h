#pragma once
#include <SFML/System.hpp>
#include "Weapon/Shooter.h"

namespace ph
{
    class BulletShooter : public Shooter
    {
    public:
        BulletShooter(Actor* owningActor, float cooldownTime = 1.f);
        virtual bool canShoot() const override;
        virtual bool isOnCooldown() const override;

    private:
        virtual void shootImpl() override;
        sf::Clock m_cooldownClock;
        float m_cooldownTime;
        bool m_bFiredFirstShot;
    };
}
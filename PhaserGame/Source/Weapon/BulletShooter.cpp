#include "Weapon/BulletShooter.h"
#include "Framework/Core.h"

namespace ph
{
    BulletShooter::BulletShooter(Actor* owningActor, float cooldownTime)
        : Shooter{ owningActor }
        , m_cooldownClock{}
        , m_cooldownTime{ cooldownTime }
        , m_bFiredFirstShot{ false }
    {
    }

    bool BulletShooter::canShoot() const
    {
        if (!m_bFiredFirstShot)
        {
            return true;
        }
        if (!isOnCooldown())
        {
            return true;
        }

        return false;
    }

    bool BulletShooter::isOnCooldown() const
    {
        return m_cooldownClock.getElapsedTime().asSeconds() < m_cooldownTime;
    }

    void BulletShooter::shootImpl()
    {
        m_bFiredFirstShot = true;
        m_cooldownClock.restart();

        LOG("%s", "SHOT FIRED");
    }
}
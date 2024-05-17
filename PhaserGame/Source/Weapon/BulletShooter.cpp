#include "Weapon/BulletShooter.h"
#include "Framework/Core.h"
#include "Framework/World.h"
#include "Weapon/Bullet.h"

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

        TWeakPtr<Bullet> newBullet = getOwningActor()->getOwningWorld()
            ->spawnActor<Bullet>(getOwningActor(), "PNG/Lasers/laserBlue01.png");
        newBullet.lock()->setActorLocation(getOwningActor()->getActorLocation());
        newBullet.lock()->setActorRotation(getOwningActor()->getActorRotation());
    }
}
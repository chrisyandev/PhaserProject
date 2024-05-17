#include "Weapon/Shooter.h"

namespace ph
{
    void Shooter::shoot()
    {
        if (canShoot())
        {
            shootImpl();
        }
    }

    Shooter::Shooter(Actor* owningActor)
        : m_owningActor{ owningActor }
    {
    }
}
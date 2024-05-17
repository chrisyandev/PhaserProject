#pragma once

namespace ph
{
    class Actor;

    class Shooter
    {
    public:
        void shoot();
        virtual bool canShoot() const = 0;
        virtual bool isOnCooldown() const = 0;
        Actor* getOwner() const { return m_owningActor; }

    protected:
        Shooter(Actor* owningActor);

    private:
        virtual void shootImpl() = 0;
        Actor* m_owningActor;
    };
}
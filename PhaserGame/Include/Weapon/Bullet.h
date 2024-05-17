#pragma once
#include "Framework/Actor.h"

namespace ph
{
    class Bullet : public Actor
    {
    public:
        Bullet(World* owningWorld,
               Actor* owningActor,
               const std::string& texturePath,
               float speed = 1000.f,
               float damage = 20.f);
        virtual void tick(float deltaTime) override;
        void setSpeed(float newSpeed);
        void setDamage(float newDamage);

    private:
        void move(float deltaTime);
        Actor* m_owningActor;
        float m_speed;
        float m_damage;
    };
}
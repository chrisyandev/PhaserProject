#pragma once
#include <box2d/b2_world.h>
#include "Framework/Core.h"

namespace ph
{
    class PhysicsSystem
    {
    public:
        static PhysicsSystem& get();

    protected:
        PhysicsSystem();

    private:
        static TUniquePtr<PhysicsSystem> s_physicsSystem;
        b2World m_physicsWorld;
        float m_physicsScale;
    };
}
#include "Framework/PhysicsSystem.h"

namespace ph
{
    TUniquePtr<PhysicsSystem> PhysicsSystem::s_physicsSystem{ nullptr };

    PhysicsSystem& PhysicsSystem::get()
    {
        if (!s_physicsSystem)
        {
            s_physicsSystem = std::move(TUniquePtr<PhysicsSystem>{ new PhysicsSystem });
        }

        return *s_physicsSystem;
    }

    PhysicsSystem::PhysicsSystem()
        : m_physicsWorld{ b2Vec2_zero }
        , m_physicsScale{ 0.01f }
    {
    }
}
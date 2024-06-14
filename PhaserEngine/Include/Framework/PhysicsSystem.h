#pragma once
#include <box2d/b2_world.h>
#include "Framework/Core.h"
#include "Framework/PhysicsContactListener.h"

namespace ph
{
    class Actor;

    class PhysicsSystem
    {
    public:
        static PhysicsSystem& get();
        void step(float deltaTime);
        b2Body* addPhysicsBody(Actor* actor);
        void removePhysicsBody(b2Body* body);
        float getPhysicsScale() const { return m_physicsScale; }
        static void cleanup();

    protected:
        PhysicsSystem();

    private:
        static TUniquePtr<PhysicsSystem> s_physicsSystem;
        b2World m_physicsWorld;
        float m_physicsScale;
        int m_velocityIterations;
        int m_positionIterations;
        PhysicsContactListener m_contactListener;
        TSet<b2Body*> m_pendingPhysicsBodiesToRemove;
    };
}
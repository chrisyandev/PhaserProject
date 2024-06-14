#include "Framework/PhysicsSystem.h"
#include <box2D/b2_body.h>
#include <box2D/b2_fixture.h>
#include <box2D/b2_polygon_shape.h>
#include "Framework/Actor.h"
#include "Framework/MathUtility.h"

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

    void PhysicsSystem::step(float deltaTime)
    {
        m_physicsWorld.Step(deltaTime, m_velocityIterations, m_positionIterations);
    }

    b2Body* PhysicsSystem::addPhysicsBody(Actor* actor)
    {
        if (actor->isPendingDestroy())
        {
            return nullptr;
        }

        b2BodyDef bodyDef;
        bodyDef.type = b2_dynamicBody;
        bodyDef.userData.pointer = reinterpret_cast<uintptr_t>(actor);
        bodyDef.position.Set(actor->getActorLocation().x * getPhysicsScale(), actor->getActorLocation().y * getPhysicsScale());
        bodyDef.angle = degreesToRadians(actor->getActorRotation());

        b2PolygonShape shape;
        sf::FloatRect bounds = actor->getActorGlobalBounds();
        shape.SetAsBox((bounds.width / 2.f) * getPhysicsScale(), (bounds.height / 2.f) * getPhysicsScale());

        b2FixtureDef fixtureDef;
        fixtureDef.shape = &shape;
        fixtureDef.density = 1.0f;
        fixtureDef.friction = 0.3f;
        fixtureDef.isSensor = true;

        b2Body* body = m_physicsWorld.CreateBody(&bodyDef);
        body->CreateFixture(&fixtureDef);

        return body;
    }

    void PhysicsSystem::removePhysicsBody(b2Body* body)
    {
    }

    PhysicsSystem::PhysicsSystem()
        : m_physicsWorld{ b2Vec2_zero }
        , m_physicsScale{ 0.01f }
        , m_velocityIterations{ 8 }
        , m_positionIterations{ 3 }
        , m_contactListener{}
    {
        m_physicsWorld.SetContactListener(&m_contactListener);
        m_physicsWorld.SetAllowSleeping(false);
    }
}
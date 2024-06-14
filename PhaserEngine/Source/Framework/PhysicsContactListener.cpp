#include "Framework/PhysicsContactListener.h"
#include <box2d/b2_contact.h>
#include "Framework/Actor.h"

namespace ph
{
    void PhysicsContactListener::BeginContact(b2Contact* contact)
    {
        Actor* actorA = reinterpret_cast<Actor*>(contact->GetFixtureA()->GetBody()->GetUserData().pointer);
        Actor* actorB = reinterpret_cast<Actor*>(contact->GetFixtureB()->GetBody()->GetUserData().pointer);

        if (actorA && !actorA->isPendingDestroy())
        {
            actorA->onActorBeginOverlap(actorB);
        }
        if (actorB && !actorB->isPendingDestroy())
        {
            actorB->onActorBeginOverlap(actorA);
        }
    }

    void PhysicsContactListener::EndContact(b2Contact* contact)
    {
        Actor* actorA = nullptr;
        Actor* actorB = nullptr;

        if (contact->GetFixtureA() && contact->GetFixtureA()->GetBody())
        {
            actorA = reinterpret_cast<Actor*>(contact->GetFixtureA()->GetBody()->GetUserData().pointer);
        }
        if (contact->GetFixtureB() && contact->GetFixtureB()->GetBody())
        {
            actorB = reinterpret_cast<Actor*>(contact->GetFixtureB()->GetBody()->GetUserData().pointer);
        }

        if (actorA && !actorA->isPendingDestroy())
        {
            actorA->onActorEndOverlap(actorB);
        }
        if (actorB && !actorB->isPendingDestroy())
        {
            actorB->onActorEndOverlap(actorA);
        }
    }
}
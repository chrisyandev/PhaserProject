#pragma once
#include <box2d/b2_world.h>
#include "Framework/Core.h"

namespace ph
{
    class PhysicsContactListener : public b2ContactListener
    {
    public:
        virtual void BeginContact(b2Contact* contact) override;
        virtual void EndContact(b2Contact* contact) override;
    };
}
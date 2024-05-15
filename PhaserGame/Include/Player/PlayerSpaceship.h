#pragma once
#include "Spaceship/Spaceship.h"

namespace ph
{
    class PlayerSpaceship : public Spaceship
    {
    public:
        PlayerSpaceship(World* owningWorld, const std::string& texturePath = "PNG/playerShip1_green.png");
    };
}
#include "Player/PlayerSpaceship.h"

namespace ph
{
    PlayerSpaceship::PlayerSpaceship(World* owningWorld, const std::string& texturePath)
        : Spaceship{ owningWorld, texturePath }
    {
    }
}
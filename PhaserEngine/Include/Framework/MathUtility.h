#pragma once
#include <SFML/Graphics.hpp>

namespace ph
{
    constexpr float PI = 3.14159265359f;

    sf::Vector2f rotationToVector(float rotationInDegrees);
    float degreesToRadians(float degrees);
    float radiansToDegrees(float radians);
}
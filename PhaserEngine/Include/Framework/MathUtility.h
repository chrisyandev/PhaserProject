#pragma once
#include <SFML/Graphics.hpp>

namespace ph
{
    constexpr float PI = 3.14159265359f;

    sf::Vector2f rotationToVector(float rotationInDegrees);
    float degreesToRadians(float degrees);
    float radiansToDegrees(float radians);

    template<typename T>
    T magnitude(const sf::Vector2<T>& vector)
    {
        return std::sqrt(vector.x * vector.x + vector.y * vector.y);
    }

    template<typename T>
    sf::Vector2<T>& scaleVector(sf::Vector2<T>& vector, float multiplier)
    {
        vector.x *= multiplier;
        vector.y *= multiplier;
        return vector;
    }

    template<typename T>
    sf::Vector2<T>& normalize(sf::Vector2<T>& vector)
    {
        float vectorLength = magnitude(vector);
        if (vectorLength > 0)
        {
            vector.x /= vectorLength;
            vector.y /= vectorLength;
            return vector;
        }
        return zeroVector<T>();
    }

    template<typename T>
    sf::Vector2<T>& zeroVector()
    {
        return sf::Vector2<T>{ (T)0, (T)0 };
    }
}
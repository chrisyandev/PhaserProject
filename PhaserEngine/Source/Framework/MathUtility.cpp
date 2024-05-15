#include "Framework/MathUtility.h"

namespace ph
{
    sf::Vector2f rotationToVector(float rotationInDegrees)
    {
        float rotationInRadians = degreesToRadians(rotationInDegrees);
        return sf::Vector2f(std::cos(rotationInRadians), std::sin(rotationInRadians));
        // Octave equivalent:
        // fwd = [1; 0]
        // rmatrix = [cos(rot) -sin(rot); sin(rot) cos(rot)]
        // dir = rmatrix * fwd
    }

    float degreesToRadians(float degrees)
    {
        return degrees * PI / 180.f;
    }

    float radiansToDegrees(float radians)
    {
        return radians * 180.f / PI;
    }
}
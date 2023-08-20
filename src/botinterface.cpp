#include "botinterface.hpp"
#include "common.hpp"
#include <SFML/System/Vector2.hpp>

namespace snakeplusplus
{
    PlayerDirection lastKnownDirection = kNone;
    PlayerDirection GetBotInput(const sf::Vector2f* snakeHeadLocation, const sf::Vector2f* foodLocation)
    {
        sf::Vector2f directionDelta;
        directionDelta = *snakeHeadLocation - *foodLocation;
        if ((directionDelta.y > 0)
                && (lastKnownDirection != kDown))
            { lastKnownDirection = kUp; }
        else if ((directionDelta.y < 0)
                && (lastKnownDirection != kUp)) 
            { lastKnownDirection = kDown; }
        else if ((directionDelta.x > 0)
                && (lastKnownDirection != kRight)) 
            { lastKnownDirection = kLeft; }
        else if ((directionDelta.x < 0)
                && (lastKnownDirection != kLeft)) 
            { lastKnownDirection = kRight; }
        return lastKnownDirection;
    }
}

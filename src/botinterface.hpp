#ifndef BOTINTERFACE_HPP
#define BOTINTERFACE_HPP

#include "common.hpp"
#include <SFML/System/Vector2.hpp>

namespace snakeplusplus
{
    PlayerDirection GetBotInput(sf::Vector2f snakeHeadLocation, sf::Vector2f foodLocation);
}

#endif 

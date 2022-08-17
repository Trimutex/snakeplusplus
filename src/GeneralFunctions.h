#ifndef GENERALFUNCTIONS_H
#define GENERALFUNCTIONS_H
#include <SFML\Graphics.hpp>

sf::Vector2f CalculateNewPosition(int direction, sf::Vector2f position);
bool GlobalCollision(sf::Vector2f object1Position, sf::Vector2f object2Position);
int GenerateRandomNumber(int generationLimit);


#endif
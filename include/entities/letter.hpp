#ifndef LETTER_H
#define LETTER_H

#include <iostream>
#include <SFML/Graphics.hpp>

#include "consts.hpp"
#include "physics/collider.hpp"

class Letter
{
public:
    Letter(std::string content);

    Collider getCollider() { return Collider(body); }
    void draw(sf::RenderWindow &window, sf::Vector2f pos);
private:
    std::string content;
    sf::RectangleShape body;
};

#endif
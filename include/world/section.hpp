#ifndef SECTION_H
#define SECTION_H

#include <vector>
#include <sstream>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "consts.hpp"
#include "entities/player.hpp"

class Section
{
public:
    // directions: 1 -> right, 2 -> left, 3 -> up, 4 -> down
    Section(sf::Vector2f adjSectionOrigin, int direction);

    sf::Vector2f getSectionOrigin() { return sectionOrigin; }
    
    void draw(sf::RenderWindow &window, sf::View &view, Player player);
private:
    float sectionSize;
    sf::Vector2f sectionOrigin;
};

#endif
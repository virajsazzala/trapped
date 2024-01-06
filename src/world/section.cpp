#include "world/section.hpp"

Section::Section(sf::Vector2f adjSectionOrigin, int direction)
{
    this->sectionSize = VIEW_HEIGHT;

    switch (direction)
    {
    case 0:
        sectionOrigin.x = 0.0f;
        sectionOrigin.y = 0.0f;
        break;
    case 1:
        sectionOrigin.x = adjSectionOrigin.x + sectionSize;
        sectionOrigin.y = adjSectionOrigin.y;
        break;
    case 2:
        sectionOrigin.x = adjSectionOrigin.x - sectionSize;
        sectionOrigin.y = adjSectionOrigin.y;
        break;
    case 3:
        sectionOrigin.x = adjSectionOrigin.x;
        sectionOrigin.y = adjSectionOrigin.y - sectionSize;
        break;
    case 4:
        sectionOrigin.x = adjSectionOrigin.x;
        sectionOrigin.y = adjSectionOrigin.y + sectionSize;
        break;
    default:
        std::cerr << "Invalid direction!" << "\n";
        break;
    }
}

void switchView(sf::View &view, Player player, float sectionSize, sf::Vector2f sectionOrigin)
{
    sf::Vector2f playerOrigin = player.getPosition();

    if ((playerOrigin.x < sectionOrigin.x + (sectionSize / 2)) && 
        (playerOrigin.y < sectionOrigin.y + (sectionSize / 2)) && 
        (playerOrigin.x > sectionOrigin.x - (sectionSize / 2)) && 
        (playerOrigin.y > sectionOrigin.y - (sectionSize / 2))
    )
        view.setCenter(sectionOrigin);
}

void Section::draw(sf::RenderWindow &window, sf::View &view, Player player)
{
    // reference
    sf::Font font;
    if (!font.loadFromFile("./res/fonts/smallest_pixel-7.ttf"))
        std::cerr << "FONT COULDN'T BE LOADED!" << "\n";
    
    sf::Text text;
    text.setFont(font);

    std::ostringstream oss;
    oss << "x: " << sectionOrigin.x << ", y: " << sectionOrigin.y;

    text.setString(oss.str());
    text.setCharacterSize(40);
    text.setPosition(sectionOrigin);

    window.draw(text);

    switchView(view, player, sectionSize, sectionOrigin);
}
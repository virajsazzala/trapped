#include "entities/letter.hpp"

Letter::Letter(std::string content)
{
    this->content = content;
}

void Letter::draw(sf::RenderWindow &window, sf::Vector2f pos)
{
    sf::Font font;
    if (!font.loadFromFile("./res/fonts/smalle.ttf"))
        std::cerr << "FONT COULDN'T BE LOADED!" << "\n";
    
    sf::Text text;
    text.setFont(font);
    text.setString(content);
    text.setCharacterSize(30);
    text.setPosition((pos.x - (VIEW_HEIGHT / 2)) + 40, (pos.y - (VIEW_HEIGHT / 2)) + 40);
    
    window.draw(text);
}
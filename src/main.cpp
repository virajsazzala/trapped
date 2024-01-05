#include <iostream>
#include <SFML/Graphics.hpp>

#include "gfx/animation.hpp"
#include "entities/player.hpp"

constexpr auto VIEW_HEIGHT = 512.0f;

void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
    float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
    view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Trapped", sf::Style::Close | sf::Style::Resize);
    sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));
    
    sf::Texture playerTexture;
    playerTexture.loadFromFile("./res/sprites/main.png");

    Player player(&playerTexture, sf::Vector2u(3, 1), 0.2f, 100.0f, 100.0f);
    sf::RectangleShape r(sf::Vector2f(100.0f, 100.0f));

    float deltaTime = 0.0f;
    sf::Clock clock;

    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();

        if (deltaTime > 1.0f / 20.0f)
            deltaTime = 1.0f / 20.0f;

        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            switch (evnt.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::Resized:
                ResizeView(window, view);
                break;
            }
        }
        
        player.update(deltaTime);

        view.setCenter(player.getPosition());

        window.clear();
        window.setView(view);
        player.draw(window);
        window.draw(r);
        window.display();
    }
    return 0;
}
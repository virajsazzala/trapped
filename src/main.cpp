#include <iostream>
#include <SFML/Graphics.hpp>

#include "gfx/animation.hpp"
#include "consts.hpp"
#include "entities/player.hpp"
#include "entities/letter.hpp"
#include "world/section.hpp"

void ResizeView(const sf::RenderWindow &window, sf::View &view)
{
    float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
    view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Trapped", sf::Style::Close | sf::Style::Resize);
    sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));

    // move to playerdata file later..
    sf::Texture playerTexture;
    playerTexture.loadFromFile("./res/sprites/main.png");
    Player player(&playerTexture, sf::Vector2u(3, 1), 0.2f, 100.0f);

    // letter
    std::string content = "You alive again? I thought you'd \nstay dead this time, hm guess you \nare a tough nut to crack..";
    Letter introLetter(content);

    // spawn, center
    // sf::RectangleShape r(sf::Vector2f(50.0f, 50.0f));
    // r.setPosition(0.0f, 0.0f);

    sf::Vector2f origin(0.0f, 0.0f);
    Section o(origin, 0);
    // right
    Section ri(origin, 1);
    // left
    Section l(origin, 2);
    // up
    Section u(origin, 3);
    // down
    Section d(origin, 4);

    // Collider c(r);

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

        window.clear();
        window.setView(view);
        player.draw(window);
        // window.draw(r);
        
        o.draw(window, view, player);
        ri.draw(window, view, player);
        l.draw(window, view, player);
        u.draw(window, view, player);
        d.draw(window, view, player);

        // sf::Vector2f direction;
        // if (player.getCollider().checkCollision(c, direction, 1.0f))
        //     introLetter.draw(window, player.getPosition());

        window.display();
    }
    return 0;
}
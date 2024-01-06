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
    sf::RenderWindow window(sf::VideoMode(800, 800), "Trapped", sf::Style::Close);
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

    sf::RectangleShape stone(sf::Vector2f(100.0f, 100.0f));
    stone.setPosition(240.f, -306.f);
    stone.setOrigin(stone.getSize()/2.0f);
    sf::Texture stoneTexture;
    stoneTexture.loadFromFile("./res/sprites/rock.png");
    stone.setTexture(&stoneTexture);

    sf::RectangleShape stone2(sf::Vector2f(100.0f, 100.0f));
    stone2.setPosition(-284.f, 295.f);
    stone2.setOrigin(stone2.getSize()/2.0f);
    stone2.setTexture(&stoneTexture);

    sf::RectangleShape stone3(sf::Vector2f(100.0f, 100.0f));
    stone3.setPosition(-166.f, -47.f);
    stone3.setOrigin(stone3.getSize()/2.0f);
    stone3.setTexture(&stoneTexture);

    sf::RectangleShape stone4(sf::Vector2f(100.0f, 100.0f));
    stone4.setPosition(279.f, 310.f);
    stone4.setOrigin(stone4.getSize()/2.0f);
    stone4.setTexture(&stoneTexture);

    sf::RectangleShape grass(sf::Vector2f(200.0f, 200.0f));
    grass.setPosition(109.f, 195.f);
    grass.setOrigin(grass.getSize()/2.0f);
    sf::Texture grassTexture;
    grassTexture.loadFromFile("./res/sprites/grass1.png");
    grass.setTexture(&grassTexture);

    sf::RectangleShape grass2(sf::Vector2f(200.0f, 200.0f));
    grass2.setPosition(-35.f, -172.f);
    grass2.setOrigin(grass2.getSize()/2.0f);
    sf::Texture grass2Texture;
    grass2Texture.loadFromFile("./res/sprites/grass2.png");
    grass2.setTexture(&grass2Texture);

    sf::RectangleShape grass3(sf::Vector2f(200.0f, 200.0f));
    grass3.setPosition(-269.f, -280.f);
    grass3.setOrigin(grass3.getSize()/2.0f);
    grass3.setTexture(&grassTexture);

    sf::RectangleShape tree(sf::Vector2f(250.0f, 250.0f));
    tree.setPosition(230.0f, -51.0f);
    tree.setOrigin(tree.getSize() / 2.0f);
    sf::Texture treeTexture;
    treeTexture.loadFromFile("./res/sprites/regtree.png");
    tree.setTexture(&treeTexture);

    sf::RectangleShape tree2(sf::Vector2f(250.0f, 250.0f));
    tree2.setPosition(-237.0f, -134.0f);
    tree2.setOrigin(tree2.getSize() / 2.0f);
    tree2.setTexture(&treeTexture);

    sf::RectangleShape tree1(sf::Vector2f(250.0f, 250.0f));
    tree1.setPosition(-267.f, 108.f);
    tree1.setOrigin(tree.getSize() / 2.0f);
    sf::Texture barrentreeTexture;
    barrentreeTexture.loadFromFile("./res/sprites/barrentree.png");
    tree1.setTexture(&barrentreeTexture);
    
    
    
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

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);
            grass.setPosition(worldPos);
            std::cout << "x: " << grass.getPosition().x << " y: " << grass.getPosition().y << "\n";
        }

        sf::RectangleShape temp(sf::Vector2f(10.0f, 10.0f));
        temp.setPosition(sf::Vector2f(0.0f, 0.0f));

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

        window.draw(stone);
        window.draw(grass);
        window.draw(grass2);
        window.draw(tree);
        window.draw(temp);
        window.draw(grass3);
        window.draw(stone2);
        window.draw(stone3);
        window.draw(stone4);
        window.draw(tree1);
        window.draw(tree2);

        // sf::Vector2f direction;
        // if (player.getCollider().checkCollision(c, direction, 1.0f))
        //     introLetter.draw(window, player.getPosition());

        window.display();
    }
    return 0;
}
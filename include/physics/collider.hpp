#ifndef COLLIDER_H
#define COLLIDER_H

#include <SFML/Graphics.hpp>

class Collider
{
public:
	Collider(sf::RectangleShape& body);

	sf::FloatRect getGlobalBounds();

	void move(float dx, float dy) { body.move(dx, dy); }
	bool checkCollision(Collider& other, sf::Vector2f& direction, float displace);

private:
	sf::RectangleShape& body;
};

#endif
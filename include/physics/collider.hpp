#ifndef COLLIDER_H
#define COLLIDER_H

#include <SFML/Graphics.hpp>

class Collider
{
public:
	Collider(sf::RectangleShape& body);

	void move(float dx, float dy) { body.move(dx, dy); }

	bool checkCollision(Collider& other, sf::Vector2f& direction, float displace);
	sf::FloatRect getGlobalBounds();

private:
	sf::RectangleShape& body;
};

#endif
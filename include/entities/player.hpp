#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

#include "gfx/animation.hpp"
#include "physics/collider.hpp"

class Player
{
public:
	Player(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed);

	void update(float deltatime);
	void draw(sf::RenderWindow &window);

	sf::Vector2f getPosition() { return body.getPosition(); }
	sf::RectangleShape getBody() { return body; }
	Collider getCollider() { return Collider(body); }

private:
	float speed;
	sf::Vector2f velocity;
	sf::RectangleShape body;

	// sprite-related
	float fold;
	bool faceRight;
	unsigned int row;
	Animation animation;
};

#endif
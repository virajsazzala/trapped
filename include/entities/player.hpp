#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "gfx/animation.hpp"

class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight);
	~Player();

	void update(float deltatime);
	void draw(sf::RenderWindow& window);

	sf::Vector2f getPosition() { return body.getPosition(); }
private:
	sf::RectangleShape body;
	Animation animation;
	unsigned int row;
	float speed;
	float fold;
	bool faceRight;

	sf::Vector2f velocity;
};

#endif
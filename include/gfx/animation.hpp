#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>

class Animation
{
public:
	Animation(sf::Texture *texture, sf::Vector2u imageCount, float switchTime);

	sf::IntRect uvRect;

	void update(int row, float deltaTime, bool faceRight, float fold);

private:
	float totalTime;
	float switchTime;
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;
};

#endif
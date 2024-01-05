#include "entities/player.hpp"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight) : animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 0;
	faceRight = true;
	fold = 0;

	body.setSize(sf::Vector2f(90.0f, 100.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(206.0f, 206.0f);
	body.setTexture(texture);
}

Player::~Player()
{
}

void Player::update(float deltaTime)
{
	velocity.x = 0.0f;
	velocity.y = 0.0f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		velocity.x -= speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		velocity.x += speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		velocity.y -= speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		velocity.y += speed;

	if (velocity.x == 0.0f && velocity.y == 0.0f)
	{
		row = 0;
		fold = 1;
	}
	else
	{
		row = 0;
		fold = 3;

		if (velocity.x > 0.0f)
			faceRight = true;
		else
			faceRight = false;
	}

	animation.update(row, deltaTime, faceRight, fold);
	body.setTextureRect(animation.uvRect);
	body.move(velocity * deltaTime);
}

void Player::draw(sf::RenderWindow& window)
{
	window.draw(body);
}

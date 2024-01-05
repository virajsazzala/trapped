#include "physics/collider.hpp"

Collider::Collider(sf::RectangleShape &body) : body(body) {}

sf::FloatRect Collider::getGlobalBounds()
{
    sf::FloatRect bounds = body.getGlobalBounds();
    bounds.left += 30.0f;
    bounds.width -= 60.0f;

    bounds.top += 30.0f;
    bounds.height -= 43.0f;

    return bounds;
}

bool Collider::checkCollision(Collider &other, sf::Vector2f &direction, float displace)
{
    sf::FloatRect thisBounds = getGlobalBounds();
    sf::FloatRect otherBounds = other.getGlobalBounds();

    float dx = otherBounds.left + otherBounds.width / 2.0f - (thisBounds.left + thisBounds.width / 2.0f);
    float dy = otherBounds.top + otherBounds.height / 2.0f - (thisBounds.top + thisBounds.height / 2.0f);

    float intersectx = abs(dx) - (otherBounds.width / 2.0f + thisBounds.width / 2.0f);
    float intersecty = abs(dy) - (otherBounds.height / 2.0f + thisBounds.height / 2.0f);

    return intersectx < 0.0f && intersecty < 0.0f;
}

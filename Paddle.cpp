#include "Paddle.h"

Paddle::Paddle(float startX, float startY)
{
	p_position.x = startX;
	p_position.y = startY;
	p_padlleShape.setSize(sf::Vector2f(10, 100));
	p_speed = 600;
	isMovingtop = false;
	isMovingdown = false;
	p_padlleShape.setPosition(p_position);
}

sf::FloatRect Paddle::getPosition()
{
	return p_padlleShape.getGlobalBounds();
}

sf::RectangleShape Paddle::getShape()
{
	return p_padlleShape;
}

void Paddle::moveTop()
{
	isMovingtop = true;
}

void Paddle::moveDown()
{
	isMovingdown = true;
}

void Paddle::stopTop()
{
	isMovingtop = false;
}

void Paddle::stopDown()
{
	isMovingdown = false;
}

void Paddle::Update(sf::Time dt)
{
	if(isMovingtop)
		p_position.y -= p_speed * dt.asSeconds();
	if (isMovingdown)
		p_position.y += p_speed * dt.asSeconds();
	p_padlleShape.setPosition(p_position);
	
}
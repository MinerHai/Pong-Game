#include "ball.h"
ball::ball(float startX, float startY)
{	b_directX = 1.0f;
	b_directY = 1.0f;

	b_speed = 300;
	b_position.x = startX;
	b_position.y = startY;
	
	b_ballShape.setSize(sf::Vector2f(15, 15));
	
	b_ballShape.setPosition(b_position);
}

sf::FloatRect ball::getposition()
{
	return b_ballShape.getGlobalBounds();
}

sf::RectangleShape ball::getShape()
{
	return b_ballShape;
}

void ball::boncesTop()
{
	b_directY = -b_directY;
}

void ball::boncesSide()
{
	b_directX = -b_directX;
}

void ball::missBottom()
{
	b_position.x = 900 / 2;
	b_position.y = 0;
}

void ball::Update(sf::Time dt)
{
	b_position.x += b_directX * b_speed * dt.asSeconds();
	b_position.y += b_directY * b_speed * dt.asSeconds();

	b_ballShape.setPosition(b_position);
}
void ball::hitball()
{
	b_directX = -b_directX;
}

void ball::boostSpeed()
{
	b_speed += 50;
}

#pragma once
#include <sfml/Graphics.hpp>

class ball
{

private:
	sf::Vector2f b_position;
	sf::RectangleShape b_ballShape;
	
	float b_directX;
	float b_directY;
	float b_speed;
public:
	ball(float startX, float startY);
	sf::FloatRect getposition();
	sf::RectangleShape getShape();
	
	void boncesTop();
	void boncesSide();
	void missBottom();
	void hitball();
	void boostSpeed();
	void Update(sf::Time dt);
};


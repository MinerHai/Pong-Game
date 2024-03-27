#pragma once
#include <SFML/Graphics.hpp>
class Paddle
{
private:
	sf::Vector2f p_position;
	sf::RectangleShape p_padlleShape;

	float p_speed;
	bool isMovingtop = false;
	bool isMovingdown = false;

public:
	Paddle(float startX, float startY);
	sf::FloatRect getPosition();
	sf::RectangleShape getShape();
	void moveTop();
	void moveDown();
	void stopTop();
	void stopDown();
	void Update(sf::Time dt);
};


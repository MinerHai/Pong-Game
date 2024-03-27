#include <SFML/Graphics.hpp>
#include <sstream>
#include "ball.h"
#include "Paddle.h"



int main()
{
	bool islive = true, isP1Win = false, isP2Win = false;
	int p1count = 0, p2count = 0;


	int winPoint = 10;
	sf::RenderWindow window (sf::VideoMode(900, 500), "Pong Game");
	ball myball(900/2, 500/2);
	Paddle mypaddle1( 30, 500/2);
	Paddle mypaddle2(900-30, 500 / 2);
	//TEXT//
	

	std::stringstream ss1, ss2;
	ss1 << "P1: " << p1count;
	ss2 << "P2: " << p2count;
	sf::Font font;
	font.loadFromFile("images/Myfont.otf");
	sf::Text textp1, textp2;
	textp1.setFont(font); textp1.setString(ss1.str()); textp1.setFillColor(sf::Color::Red);
	textp2.setFont(font); textp2.setString(ss2.str()); textp2.setFillColor(sf::Color::Red);

	textp1.setStyle(sf::Text::Bold); textp1.setCharacterSize(50);
	textp2.setStyle(sf::Text::Bold); textp2.setCharacterSize(50);

	textp1.setPosition(10, 0);
	textp2.setPosition(750, 0);
	
	


	//TIME DOT TIME


	sf::Clock clock;
	sf::Time dt;
	float bounceTime = 0.1f;

	sf::RectangleShape wall(sf::Vector2f(10, 500));
	wall.setFillColor(sf::Color::Red);
	wall.setPosition(900.0f / 2, 0);

	while (window.isOpen())
	{
		dt = clock.restart();
		bounceTime -= dt.asSeconds();

		sf::Event envt;
		while (window.pollEvent(envt))
		{
			switch (envt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			default:
				break;
			}
		}

		//Player1
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && mypaddle1.getPosition().top >= 0)
			mypaddle1.moveTop();	
		else
			mypaddle1.stopTop();
	
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && mypaddle1.getPosition().top + mypaddle1.getPosition().height<= 500)
			mypaddle1.moveDown();	
		else
			mypaddle1.stopDown();

		// Player2
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && mypaddle2.getPosition().top >= 0)
			mypaddle2.moveTop();
		else
			mypaddle2.stopTop();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && mypaddle2.getPosition().top + mypaddle2.getPosition().height <= 500)
			mypaddle2.moveDown();
		else
			mypaddle2.stopDown();
		

		//WINNER TEXT
		std::stringstream ss;
		sf::Font font;
		font.loadFromFile("images/Myfont.otf");
		sf::Text textwin;
		textwin.setFont(font);
		textwin.setCharacterSize(90);
		textwin.setStyle(sf::Text::Bold);
		textwin.setPosition(10, 400.0f / 2);
		textwin.setFillColor(sf::Color::Red);
		if (isP1Win)
		{
			ss << "P1 IS THE WINNER";
			textwin.setString(ss.str());
			islive = false;
		}
		if (isP2Win)
		{
			ss << "P2 IS THE WINNER";
			textwin.setString(ss.str());
			islive = false;
		}
		/// LOGIC HIT

		//RESET
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			islive = true; isP1Win = false; isP2Win = false;
			p1count = 0; p2count = 0;
			ball myball1(900 / 2, 500 / 2);
			myball = myball1;
			myball.hitball();
			ss1.str("");
			ss1 << "P1: " << p1count;
			textp1.setString(ss1.str());
			ss2.str("");
			ss2 << "P2: " << p2count;
			textp2.setString(ss2.str());
		}
		// COUNT POINTS
		if (myball.getposition().left + myball.getposition().width >= 900)
		{
			
			p1count++;
			ss1.str("");
			ss1 << "P1: " << p1count;
			textp1.setString(ss1.str());
			ball myball1(100, 500 / 2);
			myball = myball1;
			if (p1count >= winPoint)
				isP1Win = true;
				
			
		}
		if (bounceTime < 0 && myball.getposition().left < 0.1f)
		{
			p2count++;
			ss2.str("");
			ss2 << "P2: " << p2count;
			textp2.setString(ss2.str());
			ball myball1(800, 500 / 2);
			myball = myball1;
			myball.hitball();
			if (p2count >= winPoint)
				isP2Win = true;
		}

		/// BOUNCE
		
		if (bounceTime < 0 && (myball.getposition().top < 0.1f || myball.getposition().top + myball.getposition().height >= 500))
		{
			myball.boncesTop();
			bounceTime = 0.1f;
		}

		if (myball.getposition().intersects(mypaddle1.getPosition()) && bounceTime < 0)
		{
			myball.hitball();
			bounceTime = 0.1f;
			myball.boostSpeed();
		}
		if (myball.getposition().intersects(mypaddle2.getPosition()) && bounceTime < 0)
		{
			myball.hitball();
			bounceTime = 0.1f;
			myball.boostSpeed();
		}
		//draw
		window.clear();

		window.draw(wall);
		if (islive)
			myball.Update(dt);
		mypaddle1.Update(dt);
		mypaddle2.Update(dt);
		

		window.draw(myball.getShape());
		window.draw(mypaddle1.getShape());
		window.draw(mypaddle2.getShape());
		
		//
		window.draw(textp1);
		window.draw(textp2);
		window.draw(textwin);
		

		window.display();
	}
	return 0;
}
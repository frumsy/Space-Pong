#ifndef PADDLE_H
#define PADDLE_H

#include <SFML\Graphics.hpp>
#include <math.h>
#include <iostream>
#include "..\Globals.h"


class Paddle
{

public:
	Paddle();
	void render(sf::RenderWindow &window);
	void trackCenter(sf::RenderWindow &window);
	void move(sf::RenderWindow &window);
	void move(float deltaTime);
	
	//setters
	void setSpeed(float num);
	void setRadius(float num); 
	void setPosition(float x, float y);
	void setOrbitPoint(sf::Vector2f p);

	//Get functions:
	sf::Sprite getSprite();
	float getSpeed();
	float getRadius();
	float getLookAngle();
	sf::VertexArray getNormal();
private:
	const float PI = 3.14159265;
	float radius;
	float rotation = 0;//Angle that the Paddle is facing.
	sf::Vector2f m_speed;
	sf::Vector2f orbitPoint;
	float speed = 0;
	float lookAngle;//Angle that the Paddle is facing.

	//for debug:
	sf::VertexArray roationLine = sf::VertexArray(sf::Lines, 2);
	sf::VertexArray normalLine = sf::VertexArray(sf::Lines, 2);

	//

	sf::Texture texture;//Paddle texture
	sf::Sprite sprite;//Paddle sprite
};
#endif
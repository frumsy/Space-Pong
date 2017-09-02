#ifndef PADDLE1_H
#define PADDLE1_H

#include <SFML\Graphics.hpp>
#include <stdlib.h>
#include <math.h>
#include <iostream>


class Paddle1
{
public:
	Paddle1();
	void render(sf::RenderWindow &window);
	void trackCenter(sf::RenderWindow &window);
	void move(sf::RenderWindow &window);
	
	//setters 
	void setSpeed(float num);
	void setRadius(float num); 
	void setPosition(float x, float y);

	//Get functions:
	sf::Sprite getSprite();
	float getSpeed();
	float getRadius();
	


private:
	const float PI = 3.14159265;
	float radius;
	float rotation = 0;//Angle that the Paddle is facing.
	float speed = 0;
	float lookAngle;//Angle that the Paddle is facing.

	sf::RectangleShape rectangle;

	sf::Texture texture;//Paddle texture
	sf::Sprite sprite;//Paddle sprite
};

#endif
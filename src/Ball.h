#ifndef BALL_H
#define BALL_H

#include <SFML\Graphics.hpp>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include "Globals.h"


class Ball
{
public:
	Ball(sf::RenderWindow &window);
	void render(sf::RenderWindow &window);
	void setSpeed(float x, float y);
	sf::Vector2f findVel(const sf::Vector2f& aPos, const sf::Vector2f& bPos, float speed);
	sf::Vector2f getPos();
	float bounce(sf::VertexArray padLine, float lookAngle, sf::FloatRect &intersection);
	void move(float dTime);
	sf::CircleShape getCircle();
	float maxSpeed = .4;


private:
	sf::VertexArray ballLine = sf::VertexArray(sf::Lines, 2);
	sf::VertexArray reflectLine = sf::VertexArray(sf::Lines, 2);
	sf::VertexArray paddleLine = sf::VertexArray(sf::Lines, 2);
	sf::VertexArray acuteAngle = sf::VertexArray(sf::Triangles,3);
	sf::VertexArray obtuseAngle = sf::VertexArray(sf::Triangles,3);
	sf::Vector2f m_speed;
	sf::CircleShape circle;
	sf::Vector2f center;
};

#endif
#include "Paddle1.h"

Paddle1::Paddle1()
{
rectangle.setSize(sf::Vector2f(16,32));
texture.loadFromFile("../src/Resources/Textures/Paddle.jpg");
texture.setSmooth(false);
sprite.setTexture(texture);
sprite.setOrigin(8, 8);

}

void Paddle1::setPosition(float x, float y)
{
	rectangle.setPosition(x, y);
}

void Paddle1::setSpeed(float num)
{
	speed = num;
}

void Paddle1::setRadius(float num)
{
	radius = num;
}

float Paddle1::getSpeed()
{
	return speed;
}

float Paddle1::getRadius()
{
	return radius;
}

sf::Sprite Paddle1::getSprite() 
{
	return sprite;
}

void Paddle1::render(sf::RenderWindow &window)
{
	window.draw(rectangle);
}

void Paddle1::move(sf::RenderWindow &window)
{	
	rotation += speed;
	sf::Vector2f center = window.getView().getCenter();

	float posX = center.x + ((cosf(rotation * (PI / 180))) * radius);
	float posY = center.y + ((sinf(rotation * (PI / 180))) * radius);

	if(speed !=0)
	{
	rectangle.setPosition(posX, posY);
	}

}

void Paddle1::trackCenter(sf::RenderWindow &window)
{
	sf::Vector2f curPos = sprite.getPosition();
	sf::Vector2f center = window.getView().getCenter();

	float distanceX = curPos.x - center.x;
	float distanceY = curPos.y - center.y;

	lookAngle = (atan2(distanceY, distanceX)) * 180 / PI;
	rectangle.setRotation(lookAngle);
}
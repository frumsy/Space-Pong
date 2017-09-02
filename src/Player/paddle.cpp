#include "Paddle.h"

Paddle::Paddle()//1 for blue 2 for red
{
texture.loadFromFile("../src/Resources/Textures/Paddle.jpg");
texture.setSmooth(false);
sprite.setTexture(texture);
sprite.setOrigin(8, 8);
}

void Paddle::setPosition(float x, float y)
{
	sprite.setPosition(x, y);
}

void Paddle::setRadius(float num)
{
	radius = num;
}

void Paddle::setOrbitPoint(sf::Vector2f p)
{
	orbitPoint = p;
}


float Paddle::getSpeed()
{
	return speed;
}

float Paddle::getRadius()
{
	return radius;
}

float Paddle::getLookAngle()
{
	return lookAngle;
}

sf::Sprite Paddle::getSprite() 
{
	return sprite;
}

void Paddle::render(sf::RenderWindow &window)
{
	window.draw(sprite);
	window.draw(roationLine);
	window.draw(normalLine);
}

void Paddle::move(sf::RenderWindow &window)
{	
	rotation += speed;
	sf::Vector2f center = window.getView().getCenter();

	float posX = center.x + ((cosf(rotation * (PI / 180))) * radius);
	float posY = center.y + ((sinf(rotation * (PI / 180))) * radius);

	if(speed !=0)
	{
	sprite.setPosition(posX, posY);
	}

}

/*
void Paddle::setSpeed(float num)
{
	speed = num;
}
*/

sf::VertexArray Paddle::getNormal()
{
	return normalLine;
}

void Paddle::setSpeed(float num)
{	
	sf::Vector2f dist = sprite.getPosition() - orbitPoint;
	sf::Vector2f currentPos = sprite.getPosition();
	float rotationSlope = dist.y/dist.x;
	float normalSlope = Globals::findNormalSlope(rotationSlope);
	float b = currentPos.y - (normalSlope * currentPos.x);
	if(dist.y >= 0)
	{
		num = num * -1;
		//std::cout<<"positive"<<std::endl;
	}
	else
	{
		//std::cout<<"negative"<<std::endl;
	}

	sf::Vector2f toGo(currentPos.x + 1, ((currentPos.x +1) * normalSlope) + b);

	//sf::Vector2f goTo = currentPos + (sf::Vector2f(1,1) * normalSlope); 
	//float angle = atan2(dist.x, dist.y);
	//std::cout<<"debug: "<< normalSlope<<std::endl;
	//=========DEBUG line for rotation
	//startline[0].position = ball.getPos();
	//startline[1].position =  window.getView().getCenter();	
	roationLine[0].position = orbitPoint;
	roationLine[1].position = currentPos;
	roationLine[0].color = sf::Color::Red;
	roationLine[1].color = sf::Color::Red;
	//===========

	//=========DEBUG for normal line	
	normalLine[0].position.x = -2 * currentPos.x;
	normalLine[0].position.y = ((currentPos.x *-2) * normalSlope) + b;
	normalLine[1].position.x = currentPos.x *2;
	normalLine[1].position.y = ((currentPos.x *2) * normalSlope) + b;
	normalLine[0].color = sf::Color::Blue;
	normalLine[1].color = sf::Color::Blue;
	//===========

	m_speed = Globals::findVel(currentPos,toGo, num);

}

void Paddle::move(float deltaTime)
{
	sprite.move(m_speed * (deltaTime * 1000) );
}

void Paddle::trackCenter(sf::RenderWindow &window)
{
	sf::Vector2f curPos = sprite.getPosition();
	sf::Vector2f center = window.getView().getCenter();

	float distanceX = curPos.x - center.x;
	float distanceY = curPos.y - center.y;

	lookAngle = (atan2(distanceY, distanceX)) * 180 / PI;
	sprite.setRotation(lookAngle);
}
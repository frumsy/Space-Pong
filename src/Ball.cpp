#include "Ball.h"

Ball::Ball(sf::RenderWindow &window)
{
	circle.setRadius(7);
	circle.setFillColor(sf::Color(250, 250, 250));
	center = window.getView().getCenter();
	sf::Vector2f windowDim = window.getView().getSize();
	//std::cout<<"view size: "<<(int)windowDim.x << " "<<(int)windowDim.y <<std::endl;
	//spawn the ball at randome
	srand(time(0));
	int leftSpawn = (rand() % ((int)center.x - 32)) + (int)circle.getRadius();
	int rightSpawn = (rand() % (int)windowDim.x);

	int upSpawn = rand() % ((int)center.y - 32) + circle.getRadius();
	int downSpawn = rand() % (int)windowDim.y;
	
	int xPos = leftSpawn;
	if(rand() % 2)
	{
		xPos = rightSpawn;
		//std::cout<<"rightSpawn:"<<std::endl;
	}
	int yPos = upSpawn;
	if(rand() % 2)
	{
		yPos = downSpawn;
		//std::cout<<"downSpawn:"<<std::endl;
	}
	//std::cout<<"x: "<< xPos <<" y: "<<yPos<<std::endl;
	circle.setPosition(xPos, yPos);
	m_speed = findVel(sf::Vector2f(xPos,yPos), center, maxSpeed);
}

sf::CircleShape Ball::getCircle()
{
	return circle;
}

void Ball::render(sf::RenderWindow &window)
{
	window.draw(circle);
	window.draw(ballLine);
	window.draw(reflectLine);
	window.draw(paddleLine);
	window.draw(acuteAngle);
	window.draw(obtuseAngle);
}

sf::Vector2f Ball::getPos()
{
	return circle.getPosition();
}


sf::Vector2f Ball::findVel(const sf::Vector2f& aPos, const sf::Vector2f& bPos, float speed) {
    sf::Vector2f disp = bPos-aPos;
    //float distance    = sqrt(disp.x*disp.x+disp.y*disp.y); // 
	float distance = std::hypot(disp.x, disp.y);
    return disp * (speed/distance);
}

void Ball::setSpeed(float x, float y)
{
	m_speed = findVel(circle.getPosition(), center, maxSpeed);
}

void Ball::move(float dTime)
{
	circle.move(m_speed * (dTime * 1000));
}


float Ball::bounce(sf::VertexArray padLine, float lookAngle, sf::FloatRect &intersection)
{
	sf::Vector2f hitPoint(intersection.left, intersection.top);
	//std::cout<<"rect: "<< hitPoint.x << " "<< hitPoint.y <<std::endl;
	//**
	//for visual debug of ball path before collision:
	ballLine[0].position.x = circle.getPosition().x;
	ballLine[0].position.y = circle.getPosition().y;
	ballLine[1].position.x = circle.getPosition().x - (-1000 * m_speed.x);
	ballLine[1].position.y = circle.getPosition().y - (-1000 * m_speed.y);	
	ballLine[0].color = sf::Color::Green;
	ballLine[1].color = sf::Color::Green;
	//

	//get the slope of paddle line
	sf::Vector2f padDist(padLine[0].position.x - padLine[1].position.x, padLine[0].position.y - padLine[1].position.y);
	float padSlope = padDist.y/padDist.x;

	//for visual the normal line adjusted to the position that the ball hits the paddle at.
	paddleLine[0].position.x = circle.getPosition().x;
	paddleLine[0].position.y = circle.getPosition().y;
	paddleLine[1].position.x = circle.getPosition().x - circle.getPosition().x + 1;
	paddleLine[1].position.y = circle.getPosition().y - ((circle.getPosition().x + 1) * padSlope);
	paddleLine[0].color = sf::Color::Cyan;
	paddleLine[1].color = sf::Color::Cyan;
	//

	float innerAngle = Globals::findInnerAngle(ballLine[0].position, ballLine[1].position, paddleLine[1].position);	

	float ball_dx = circle.getPosition().x - (circle.getPosition().x - (1000 * m_speed.x));
	float ball_dy = circle.getPosition().y - (circle.getPosition().y - (1000 * m_speed.y));

	sf::Vector2f ball_dist(ball_dx, ball_dy);
	sf::Vector2f paddle_dist = padLine[0].position - padLine[1].position;
	
	float paddleHypot = std::hypot(paddle_dist.x, paddle_dist.y);
	float ballHypot = std::hypot(ball_dist.x, ball_dist.y);

	//get the angle between the lines:
	float hitAngle = acos( (ball_dist.x * paddle_dist.x + ball_dist.y * paddle_dist.y) / (paddleHypot * ballHypot) );

	//for visual debug of reflect line:
	reflectLine[0].position.x = circle.getPosition().x;
	reflectLine[0].position.y = circle.getPosition().y;
	float combinedAngle = hitAngle;//-lookAngle;
	float ratioY = sin(combinedAngle);
	float ratioX = cos(combinedAngle);
	sf::Vector2f toGo(circle.getPosition().x - (circle.getPosition().x * ratioX)*1000, circle.getPosition().y - (circle.getPosition().y * ratioY)*1000);
	reflectLine[1].position.x = toGo.x;//circle.getPosition().x - (1000 * m_speed.x);
	reflectLine[1].position.y = toGo.y;//circle.getPosition().y - (1000 * m_speed.y);
	reflectLine[0].color = sf::Color::White;
	reflectLine[1].color = sf::Color::White;
	//
	//std::cout<<"ball slope: "<< m_speed.y/m_speed.x <<" : " << ratioX<<std::endl;	

	std::cout<<"Angle: "<< innerAngle * 180/3.14159265<< std::endl;
	//**	
	setSpeed(1,1);

	return 0.0;
}


/*
std::cout<<"rect: "<< intersection.left << " "<< intersection.top <<std::endl;

	//**
	//for visual debug of ball path before collision:
	ballLine[0].position.x = circle.getPosition().x;
	ballLine[0].position.y = circle.getPosition().y;
	ballLine[1].position.x = circle.getPosition().x - (1000 * m_speed.x);
	ballLine[1].position.y = circle.getPosition().y - (1000 * m_speed.y);
	ballLine[0].color = sf::Color::Green;
	ballLine[1].color = sf::Color::Green;
	//

	float ball_dx = circle.getPosition().x - (circle.getPosition().x - (1000 * m_speed.x));
	float ball_dy = circle.getPosition().y - (circle.getPosition().y - (1000 * m_speed.y));

	sf::Vector2f ball_dist(ball_dx, ball_dy);
	sf::Vector2f paddle_dist = padLine[0].position - padLine[1].position;
	
	float paddleHypot = std::hypot(paddle_dist.x, paddle_dist.y);
	float ballHypot = std::hypot(ball_dist.x, ball_dist.y);

	//get the angle between the lines:
	float hitAngle = acos( (ball_dist.x * paddle_dist.x + ball_dist.y * paddle_dist.y) / (paddleHypot * ballHypot) );

	//for visual debug of reflect line:
	reflectLine[0].position.x = circle.getPosition().x;
	reflectLine[0].position.y = circle.getPosition().y;
	float combinedAngle = hitAngle;//-lookAngle;
	float ratioY = sin(combinedAngle);
	float ratioX = cos(combinedAngle);
	sf::Vector2f toGo(circle.getPosition().x - (circle.getPosition().x * ratioX)*1000, circle.getPosition().y - (circle.getPosition().y * ratioY)*1000);
	reflectLine[1].position.x = toGo.x;//circle.getPosition().x - (1000 * m_speed.x);
	reflectLine[1].position.y = toGo.y;//circle.getPosition().y - (1000 * m_speed.y);
	reflectLine[0].color = sf::Color::White;
	reflectLine[1].color = sf::Color::White;
	//
	std::cout<<"ball slope: "<< m_speed.y/m_speed.x <<" : " << ratioX<<std::endl;	

	std::cout<<"Angle: "<<combinedAngle<<std::endl;
	//**	
	setSpeed(1,1);

	return 0.0;
*/
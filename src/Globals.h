#ifndef GLOBALS_H
#define GLOBALS_H

const float PI = 3.14159265;

class Globals{
public:

sf::Vector2f static findVel(const sf::Vector2f& aPos, const sf::Vector2f& bPos, float speed) {
	sf::Vector2f disp = bPos-aPos;
	//std::cout<<"disp: "<< disp.x <<" "<< disp.y <<std::endl;
	float distance = std::hypot(disp.x, disp.y);
	//std::cout<<"distance: "<<distance<<std::endl;
	return disp * (speed/distance);
}

float static angleToSlope(float angle, float radius)
{
	float o = sin(angle) * radius;
	float a = cos(angle) * radius;
	if(a == 0)
	{
		return 1.5708;
	}
	
	return o/a;
}

float static d2r(float degrees)
{
	return degrees * PI/180;
}

//radians to degrees
float static r2d(float radians)
{
	return radians * (180.0 / PI);
}

float static findNormalSlope(float slope)
{
	return (1/slope) * (-1);
}

//returns the angle between the intersecting lines
float static findInnerAngle(sf::Vector2f inter, sf::Vector2f a, sf::Vector2f b)
{
	//const float PI = 3.14159265;
	sf::Vector2f dispA = a - inter;		
	sf::Vector2f dispB = b - inter;
	float magA = std::hypot(dispA.x, dispA.y);
	float magB = std::hypot(dispB.x, dispB.y);
	float dotProduct = (a.x * b.x) + (a.y + b.y);
	float theta = acos( (dotProduct * .01) / (magA * magB) );
	if(dotProduct < 0)
	{
		//obtuse
		return 1 - theta;
	}
	else
	{
		return theta;// * (180.0 / PI);
	}
	//return theta * 180.0 / PI;	
}

};
#endif
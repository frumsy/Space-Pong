#ifndef PADDLECONTROLLER_H
#define PADDLECONTROLLER_H

#include <iostream>
#include "Paddle.h"

class PaddleController
{
public:
	PaddleController(Paddle &p);
	Paddle* getPaddle();
	void handleInput();
	void move();

	bool wPressed;
	bool aPressed;
	bool sPressed;
	bool dPressed;
private:
	sf::Event event;
	sf::RenderWindow* window;
	Paddle* paddle;

};
#endif
#include "PaddleController.h"

PaddleController::PaddleController(Paddle &p)
{
	paddle = &p;
}

Paddle* PaddleController::getPaddle()
{
	return paddle;
}

void PaddleController::move()
{
	//If buttons are pressed
	if (wPressed)
	{
		paddle->setSpeed(1);
	}
	if (sPressed)
	{
		paddle->setSpeed(-1);
	}

	if (wPressed == false && sPressed == false)
	{

		paddle->setSpeed(0);
	}
}

//handles keyboard inputs that will affect the paddle
void PaddleController::handleInput()
{
	wPressed = false;
	aPressed = false;
	sPressed = false;
	dPressed = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			wPressed = true;
		}
		else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			wPressed = false;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			sPressed = true;
		}
		else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			sPressed = false;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))//Left
		{
			aPressed = true;
		}
		else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			aPressed = false;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			dPressed = true;
		}
		else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			dPressed = false;
		}
	this->move();
}
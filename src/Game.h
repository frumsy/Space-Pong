#ifndef GAME_H
#define GAME_H

#include "StateManager.h"
#include "Player\Paddle.h"
#include "Player\PaddleController.h"
#include "Ball.h"
#include <iostream>

class Game : public StateManager
{

public:
	virtual int Run(sf::RenderWindow &window);
	void collision();
private:
	int bounceCount = 0;
	sf::Event event;
	std::vector<Ball> balls;
	Paddle paddle;
	bool running;
};
#endif
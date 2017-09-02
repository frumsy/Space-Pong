#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "StateManager.h"

class Menu : public StateManager
{
public:
	virtual int Run(sf::RenderWindow &window);

private:
	sf::Event event;
	bool running;
};

#endif
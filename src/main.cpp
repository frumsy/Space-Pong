#include <vector>
#include <iostream>
#include <SFML\Graphics.hpp>
#include "StateManager.h" //Custom
#include "Menu.h" //Custom
#include "Game.h" //Custom

int main()
{
	//StateManager IDs
	std::vector<StateManager*> states;
	int screenState = 0;

	sf::RenderWindow window;//	sf::RenderWindow window;
	window.create(sf::VideoMode(1280, 720, 32), "Sharaland", sf::Style::Default);

	//states
	//Menu menu;
	//states.push_back(&menu);
	Game game;
	states.push_back(&game);
	//GraphicSet state4;
	//states.push_back(&state4);

	while (screenState >= 0)
	{
		//main loop
		screenState = states[screenState]->Run(window);
	}
	return 0;
}
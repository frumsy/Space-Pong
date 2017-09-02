#include "Game.h"

int Game::Run(sf::RenderWindow &window)
{
	bool running = true;
	Background background(sf::String);

	//set game view
	sf::View gameView = window.getView();
	//window.setView(gameView);
	//gameView.reset(sf::FloatRect(200, 200, 300, 200));
	//gameView.setCenter(200, 200);

	balls.push_back(Ball(window));

	//Ball ball(window);

	/*
	sf::VertexArray startline(sf::Lines, 2);
	//startline[0].position = ball.getPos();
	//startline[1].position =  window.getView().getCenter();	
	startline[0].position = balls.front().getPos();
	startline[1].position.x = balls.front().getPos().x + (balls.front().speedX * 1000);
	startline[1].position.y = balls.front().getPos().y + (balls.front().speedY * 1000);

	startline[0].color = sf::Color::Red;
	startline[1].color = sf::Color::Blue;
	//std::cout << "balls.front().pos: " << "( " << balls.front().getPos().x << ", " << balls.front().getPos().y << ")" << std::endl;
	//std::cout << "center: " << "( " << window.getView().getCenter().x << ", " << window.getView().getCenter().y << ")" << std::endl;
	*/
	paddle.setOrbitPoint(window.getView().getCenter());
	paddle.setRadius(gameView.getSize().y/2 - 32);
	paddle.setPosition( (gameView.getSize().x/2) + paddle.getRadius(), paddle.getRadius());
	PaddleController paddleController(paddle);

	sf::Clock GameClock;
	//Main loop
	while (running)
	{
		float deltaTime = GameClock.restart().asSeconds();

		//HandleEvents(window);
		while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)//Closes program
				{
					return (-1);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					//Overlay ui
				}
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					std::cout<<"space"<<std::endl;
					balls.push_back(Ball(window));
				}
				if (event.type == sf::Event::MouseButtonPressed)
				{
					std::cout<<"LookAngle: "<< paddle.getLookAngle()<< std::endl;
					//std::cout<<""<<std::endl;
					//std::cout<<""<<std::endl;
				}
			}

		collision();
		//std::cout<<"angle: "<<paddle.getLookAngle()<<std::endl;

		//handles keyboard inputs for paddle
		paddleController.handleInput();

		paddle.trackCenter(window);
		//paddle.move(window);
		paddle.move(deltaTime);
		
		for(auto &i : balls)
		{
			i.move(deltaTime);
		}
		//balls.front().move(deltaTime);

		window.clear();
		paddle.render(window);
		for(auto &i : balls)
		{
			i.render(window);
		}
		//balls.front().render(window);
		window.display();
	}
	return (-1);
}

void Game::collision()
{
	sf::FloatRect intersection;
	for(auto& ball : balls)
	{
		if(ball.getCircle().getGlobalBounds().intersects(paddle.getSprite().getGlobalBounds(), intersection))
		{
			bounceCount++;
			ball.bounce(paddle.getNormal(),paddle.getLookAngle(),intersection);
			std::cout<<"Bounces: "<<bounceCount<<std::endl;
		}
	}
}
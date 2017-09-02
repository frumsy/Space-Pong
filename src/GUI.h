#ifndef GUI_H
#define GUI_H

#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>
	
	//Background
	class Background
	{
	public:
		Background(std::string filepath);
		void Render(sf::RenderWindow &window);
	private:
		sf::Texture bgTex;
		sf::Sprite  bgSprite;
	};

	//menu graphics
	class MenuGraphics// : public Menu
	{
	public:
		MenuGraphics();
		void Render(sf::RenderWindow &window);
		int CheckClick(int x, int y);
	private:
		
		sf::Texture MStartTex;//start button tex
		sf::Texture MOptionsTex;//option button tex
		sf::Texture MExitTex;//exit button tex

		sf::Sprite StartSprite;//Button start sprite
		sf::Sprite OptionsSprite;//Button Options sprite
		sf::Sprite ExtSprite;//Button Exit sprite
	};

	class Button// : public Menu
	{
	public:
		Button(int SpriteX, int  SpriteY, std::string filepath);
		void Render(sf::RenderWindow &window, sf::Sprite &TempSprite);
		bool CheckClick(int mMouseX, int mMouseY, sf::Sprite &TempSprite);
		sf::Sprite getSprite();
	private:
		sf::Texture btnTex;
		sf::Sprite BtnSprite;

	};
	/*
	class MovableBackground
	{
	public:
		MovableBackground();
		void Update(sf::RenderWindow &window, float elapsedTime);
		void Render(sf::RenderWindow &window);

	private:
		sf::Texture bg1Tex;
		sf::Texture bg2Tex;

		sf::Sprite  bg1Sprite;
		sf::Sprite  bg2Sprite;

		float bgSpeed;
		float bg1Y;
		float bg2Y;
	};*/

#endif





	//Movable background!
	/*
	   bgTex.loadFromFile("graphics//background.jpg");
    bgTex.setSmooth(false);
    bgTex.setRepeated(true);
    bgSprite.setTexture(bgTex);
    bgSprite.setPosition(0,0);
    bgY = 0;
    bgSprite.setTextureRect(sf::IntRect(0,bgY,800,600));

	//

	if (bgY < 600)
	{
	bgY += bgSpeed * elapsedTime;
	}
	else
	{
	bgY = 0;
	}
	bgSprite.setTextureRect(sf::IntRect(0,bgY,800,600));
	
	*/
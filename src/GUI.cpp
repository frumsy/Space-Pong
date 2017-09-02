#include "GUI.h"
#include <iostream>

//Background
Background::Background(std::string filepath)
{
	bgTex.loadFromFile(filepath);
	bgTex.setSmooth(false);
	bgSprite.setTexture(bgTex);
	bgSprite.setPosition(0, 0);
}

void Background::Render(sf::RenderWindow &window)
{
	window.draw(bgSprite);
}

MenuGraphics::MenuGraphics()
{
	//load Start button sprite
	MStartTex.loadFromFile("../src/Resources/Textures/StartButton.png");
	MStartTex.setSmooth(false);
	StartSprite.setTexture(MStartTex);
	StartSprite.setPosition(300, 0);
	//Load Options Button sprite
	MOptionsTex.loadFromFile("../src/Resources/Textures/OptionsButton.png");
	MOptionsTex.setSmooth(false);
	OptionsSprite.setTexture(MOptionsTex);
	OptionsSprite.setPosition(300, 360);
	//Load Exit button sprite
	MExitTex.loadFromFile("../src/Resources/Textures/ExitButton.png");
	MExitTex.setSmooth(false);
	ExtSprite.setTexture(MExitTex);
	ExtSprite.setPosition(300, 600);
}

void MenuGraphics::Render(sf::RenderWindow &window)
{
	//button sprite draw calls
	window.draw(StartSprite);
	window.draw(OptionsSprite);
	window.draw(ExtSprite);
}

int MenuGraphics::CheckClick(int x, int y)
{
	//Check to see if start button is clicked
	if (x > StartSprite.getPosition().x &&
		y > StartSprite.getPosition().y &&
		x < StartSprite.getPosition().x + StartSprite.getLocalBounds().width &&
		y < StartSprite.getPosition().y + StartSprite.getLocalBounds().height)
	{
		std::cout << "start ";
		return 2;
	}

	//Check to see if Options button is clicked
	if (x > OptionsSprite.getPosition().x &&
		y > OptionsSprite.getPosition().y &&
		x < OptionsSprite.getPosition().x + OptionsSprite.getLocalBounds().width &&
		y < OptionsSprite.getPosition().y + OptionsSprite.getLocalBounds().height)
	{
		std::cout << "options ";
		return 1;
	}

	//Check to see if exit is clicked
	if (x > ExtSprite.getPosition().x &&
		y > ExtSprite.getPosition().y &&
		x < ExtSprite.getPosition().x + ExtSprite.getLocalBounds().width &&
		y < ExtSprite.getPosition().y + ExtSprite.getLocalBounds().height)
	{
		std::cout << "exit ";
		return -1;
	}
	return 0;

}

Button::Button(int SpriteX, int  SpriteY, std::string filepath)
{
	btnTex.loadFromFile(filepath);
	btnTex.setSmooth(false);
	BtnSprite.setTexture(btnTex);
	BtnSprite.setPosition(SpriteX, SpriteY);
}

sf::Sprite Button::getSprite()
{
	return BtnSprite;
}

void Button::Render(sf::RenderWindow &window, sf::Sprite &TempSprite)
{
	window.draw(TempSprite);
}

bool Button::CheckClick(int mMouseX, int mMouseY, sf::Sprite &TempSprite)
{
	//Check to see if start button is clicked
	if (mMouseX > TempSprite.getPosition().x &&
		mMouseY > TempSprite.getPosition().y &&
		mMouseX < TempSprite.getPosition().x + TempSprite.getLocalBounds().width &&
		mMouseY < TempSprite.getPosition().y + TempSprite.getLocalBounds().height)
	{
		return true;
	}

	else
	{ 
		return false; 
	}
}
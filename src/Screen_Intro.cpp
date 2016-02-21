#include "Screen_Intro.h"
#include <iostream>

Screen_Intro Screen_Intro::myIntro;

Screen_Intro::Screen_Intro()
{

}

void Screen_Intro::Init()
{
	std::cout << "Intro Screen Start" << std::endl;
}

void Screen_Intro::Cleanup()
{
	std::cout << "Intro Screen Quit" << std::endl;
}

void Screen_Intro::Pause()
{

}

void Screen_Intro::Unpause()
{

}

void Screen_Intro::HandleEvents(GameEngine* game)
{
	std::cin.ignore();
}

void Screen_Intro::Update(GameEngine* game)
{
	//quit the game
	game->PopScreen();
}

void Screen_Intro::Draw(GameEngine* game)
{
	std::cout << "Intro : Type something to quit" << std::endl;
}

Screen_Intro* Screen_Intro::Instance()
{
	return &myIntro;
}
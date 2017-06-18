#include "Game.h"
Game::Game(RenderWindow& wnd) :
	window(wnd),
	level("file"),
	tom("0001", 2, "/tom", level)
{
}

void Game::run(float time_elapsed)
{
	update();
	render(time_elapsed);
}

void Game::render(float time_elapsed)
{	
	window.clear();
	level.draw(window);
	tom.draw(window, time_elapsed);
	window.display();
}

void Game::update()
{
	playerInput();
	tom.checkCollision(window);
}

void Game::playerInput()
{
	//keyboard input for moving main char
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		tom.run('r');
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		tom.run('l');
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		tom.run('u');
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		tom.run('d');
	}
	else
		tom.run('\0');
}


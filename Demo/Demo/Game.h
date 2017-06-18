#pragma once
#include "stdafx.h"
#include "Player.h"

using namespace sf;
class Game
{
	RenderWindow& window;
	Event event;
	Player tom;
	TileMap level;
	void update();
	void render(float);
	void playerInput();
public:
	Game(RenderWindow&);
	void run(float);
};


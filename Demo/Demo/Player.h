#pragma once
#include "stdafx.h"
#include "Char.h"

using namespace sf;
using namespace std;


class Player : public Char
{
public:
	using Char::Char;
	explicit Player(string id, double speed, string filename, TileMap& in_level) : Char(id, speed, filename, in_level) {};
	void run(char dir); //move the player character in a direction
};


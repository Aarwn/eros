#pragma once

#include "stdafx.h" //precompiled header
#include "TileMap.h"

using namespace sf; //sfml
using namespace std; //standard library

class Char : public Mesh
{
protected:
	int dim[2] = { 36, 64 }/*width and height of sprite respectively*/, flip = 0; //counter for slowing down animation
	double speed; //movement speed
	TileMap level;
public:
	Char() : Mesh()
	{
		speed = 0;
		TileMap t("/testlevel");
	}
	using Mesh::Mesh;
	explicit Char(string id, double in_speed, string filename, TileMap& in_level) : Mesh(id, filename)
	{
		level = TileMap(in_level);
		speed = in_speed;
		textures["left"].loadFromFile("left.png");
		textures["right"].loadFromFile("right.png");
		textures["neutral"].loadFromFile("neutral.png");
	}
		
		//id, speed, filename of textures, level to be spawned in
	string getID()
	{
		return id;
	}
	double getSpeed()
	{
		return speed;
	}

	void checkCollision(RenderWindow& wnd);
};


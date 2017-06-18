#pragma once

#include "stdafx.h"
#include "Mesh.h"

using namespace std;
using namespace sf;

enum TEXTURE//All possible ground tiles
{
	//WASH MISSING
	GRASS,
	SNOW,
	SHALLOW,
	SAND,
	SANDWEEDS1,
	SANDWEEDS2,
	HEATHER,
	BRACKEN,
	MOSS2,
	LEAFLITTER,
	SNOWGRASS,
};

class TileMap //level map consisting of tiles
{
	class Tile : public Mesh
	{
		TEXTURE texture;
		int x, y;
	public:
		Tile() {};
		using Mesh::sprt;
		Tile(TEXTURE, int, int);
		TEXTURE getTexture();
		int getX();
		int getY();
	};
	Tile tiles[16][16];
protected:
	static Texture textures[11];
public:
	TileMap()
	{
		int x, y;
		for (int i = 0; i < 16; i++)
		{
			for (int j = 0; j < 16; j++)
			{
				x = j * 64;
				y = i * 64;
				tiles[i][j] = Tile(GRASS, x, y);
			}
		}
		textures[GRASS].loadFromFile("grass.png");
	}
	TileMap(string);
	void draw(RenderWindow& wnd);
	
};


#include "TileMap.h"

TileMap::TileMap(string)
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

Texture TileMap::textures[11];

void TileMap::draw(RenderWindow & wnd)
{
	TEXTURE tile_tex = GRASS;
	Texture& tex_ref = textures[tile_tex];
	
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			Tile tile = tiles[i][j];
			if (tile.getTexture() != tile_tex)
			{
				tile_tex = tile.getTexture();
				tex_ref = textures[tile_tex];
			}
			tile.draw(wnd, 0.0, tex_ref, tile.getX(), tile.getY());
		}
	}
}


TileMap::Tile::Tile(TEXTURE t, int in_x, int in_y) 
{
	texture = t;
	x = in_x;
	y = in_y;
}

int TileMap::Tile::getX()
{
	return x;
}

int TileMap::Tile::getY()
{
	return y;
}

TEXTURE TileMap::Tile::getTexture()
{
	return texture;
}
#pragma once
#include "stdafx.h"
using namespace sf;
using namespace std;
class Mesh
{
protected:
	string id; //unique id for every object in the game
	int dim[2] = { 36, 64 };/*width and height of sprite respectively*/
	Sprite sprt; //the sprite related to the object
	static map<string, Texture> Mesh::textures; //map of all textures related to the sprite, i.e. side strafe, south-standing, attacking
	IntRect rectRun; //the frame that moves through the spritemap, giving animation
public:
	Mesh()
	{
		id = "000";
	}
	explicit Mesh(string, string);
	void draw(RenderWindow&, float); //draw character to window
	void draw(RenderWindow&, float, Texture&, int, int);
	map<string, Texture> getTextureMap()
	{
		return textures;
	}
};


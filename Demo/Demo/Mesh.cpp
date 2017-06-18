#include "Mesh.h"

map<string, Texture> Mesh::textures;

Mesh::Mesh(string id, string filename)
{
	this->id = id;
	//get all sprites in directory and read into dictionary
	//--TO BE COMPLETED--
	/*string srch_path = filename + "/*.png";
	WIN32_FIND_DATA fd;
	HANDLE hFind = ::FindFirstFile(srch_path.c_str(), &fd);
	if (hFind != INVALID_HANDLE_VALUE)
	{
	do
	{
	if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
	{
	tex_map.insert()
	}
	}
	}*/

	//when file reading works,

	//until above code for loading all textures works

	rectRun = IntRect(0, 0, dim[0], dim[1]);
	sprt = Sprite(textures["neutral"], rectRun);
}

void Mesh::draw(RenderWindow& wnd, float time_elapsed)
{
	sprt.setTextureRect(rectRun); //initialise the frame for animation, to the first position of the character
	if (rectRun.left == 17 * dim[0])
	{
		rectRun.left = 0;
	}
	else
		rectRun.left += dim[0];
	wnd.draw(sprt);//draw sprite to screen
}

void Mesh::draw(RenderWindow& wnd, float time_elapsed, Texture& tex, int x, int y)
{
	sprt.setTexture(tex);
	sprt.setPosition(x, y);
	wnd.draw(sprt);//draw sprite to screen
}

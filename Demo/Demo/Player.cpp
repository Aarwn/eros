#include "Player.h"

void Player::run(char dir)
{
	if (dir == 'l') //player needs to move left
	{
		sprt.move(speed*-1, 0); //update the characters position, based on their speed, to move to the left
		sprt.setTexture(textures["left"]); //load the left facing run textures
		sprt.setTextureRect(rectRun); //initialise the frame for animation, to the first position of the character
	}
	else if (dir == 'r')//same as above but with right facing running animation, and moving to the right
	{
		sprt.setTexture(textures["right"]);
		sprt.setTextureRect(rectRun); //initialise the frame for animation, to the first position of the character
		sprt.move(speed, 0);
	}
	else if (dir == 'u')//same as above but with back facing running animation, and moving up
	{
		sprt.setTexture(textures["neutral"]);//until Aran animates the last two running animations
		rectRun.left = 0;
		sprt.move(0, speed*-1);
	}
	else if (dir == 'd')//same as above but with front facing running animation, and moving down
	{
		sprt.setTexture(textures["neutral"]);//until Aran animates the last two running animations
		rectRun.left = 0;
		sprt.move(0, speed);
	}
	else if (dir == '\0')//no keys are pressed so the character must simply stand still, facing the camera
	{
		sprt.setTexture(textures["neutral"]);
		rectRun.left = 0;//reset the frame ready for when movement causes animation
	}
}


#include "Game.h"

int main()
{
	RenderWindow window(VideoMode(1024, 1024), "Eros");
	Event event;
	Game game(window);

	//initialise time of previous frame to first frame
	clock_t last = clock();
	//main game loop
	while (window.isOpen())
	{
		/*clock_t now = clock();
		float difference = last - now;*/
		//check for window still open
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		game.run(0.0/*difference*/);
		//set time of previous frame as current frame ends
		//last = now;
	}

	return 0;
}
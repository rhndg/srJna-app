#include "global.h"

int fun(){
	sf::Texture texWire;
	if (!texWire.loadFromFile("rsc/wire.png"))
	{
	    return EXIT_FAILURE;
	}
	sf::Sprite spriteWire(texWire);

	window->clear();
	window->draw(spriteWire);
	window->display();
}
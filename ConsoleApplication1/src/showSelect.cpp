//#include "global.h"
#include "electricity/electricity.cpp"

int showSelect(){
	sf::Texture texWire;
	if (!texWire.loadFromFile("rsc/select.png"))
	{
		return EXIT_FAILURE;
	}
	sf::Sprite spriteWire(texWire);

	window->clear();
	window->draw(spriteWire);
	window->display();
	while (window->isOpen()){
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			gameMain();
		}
	}
}
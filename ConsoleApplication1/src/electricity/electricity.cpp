#include "../global.h"

sf::Clock clk;
sf::Time tme = clk.getElapsedTime();
void delayTime(float f)
{
	clk.restart();
	tme = clk.getElapsedTime();
	while (tme.asSeconds() < f)
	{
		tme = clk.getElapsedTime();
	}
}

int gameMain(){
    //window->setMouseCursorVisible(true);

    sf::Texture texWire;
    if (!texWire.loadFromFile("rsc/wire.png"))
    {
        return EXIT_FAILURE;
    }
    sf::Sprite spriteWire(texWire);

    sf::Texture texBOff;
    if (!texBOff.loadFromFile("rsc/boff.png"))
    {
        return EXIT_FAILURE;
    }
    sf::Sprite spriteBOff(texBOff);

    sf::Texture texBOn;
    if (!texBOn.loadFromFile("rsc/bon.png"))
    {
        return EXIT_FAILURE;
    }
    sf::Sprite spriteBon(texBOn);
	
	sf::Texture texSelect;
	if (!texSelect.loadFromFile("rsc/select.png"))
	{
		return EXIT_FAILURE;
	}
	sf::Sprite spriteSel(texSelect);

	window->clear();
	window->draw(spriteSel);
	window->display();

    while(window->isOpen())
    {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            window->clear();
            window->draw(spriteWire);
            window->display();
            delayTime(3);
            break;
        }
    }

    bool bOn = 0;
    while(window->isOpen())
    {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            window->clear();
            window->draw(spriteBOff);
            window->display();
            delayTime(0.5);
            break;
        }
    }

    while(window->isOpen())
    {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
        	//window->close();
             window->clear();
             window->draw(spriteBon);
             window->display();
             bOn = 1;
             delayTime(0.5);
        }
        else if(bOn==1 && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            window->clear();
            window->draw(spriteBOff);
            window->display();
            bOn = 0;
            delayTime(0.5);
			break;
        }
    }
	while (window->isOpen()){
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			window->close();
		}
	}
}
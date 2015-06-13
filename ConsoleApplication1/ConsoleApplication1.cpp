// ConsoleApplication1.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "sub.cpp"

/**
 * @brief render a window
 * @details creates a new window using sf::RenderWindow
 *
 * @param w width
 * @param t height
 */
void renderWindow(){
    window = new sf::RenderWindow(sf::VideoMode(1366, 768), "Electric Circuit");
}

sf::Clock clk;
sf::Time tme = clk.getElapsedTime();
void delayTime(float f)
{
    clk.restart();
    tme = clk.getElapsedTime();
    while(tme.asSeconds() < f)
    {
        tme = clk.getElapsedTime();
    }
}

/**
 * @brief events after window is rendered
 */
int gameMain(){
    //window->setMouseCursorVisible(true);

    /**
     * @brief set window frame rate
     */
    //window->setFramerateLimit(60);

    /**
     * @brief load texture for table in texture
     */
    sf::Texture texBack;
    if (!texBack.loadFromFile("rsc/background.png"))
    {
        return EXIT_FAILURE;
    }
    sf::Texture texWelcome;
    if (!texWelcome.loadFromFile("rsc/welcome.png"))
    {
        return EXIT_FAILURE;
    }
    sf::Texture texSprite1;
    if (!texSprite1.loadFromFile("rsc/sprite1.png"))
    {
        return EXIT_FAILURE;
    }
    sf::Texture texSprite2;
    if (!texSprite2.loadFromFile("rsc/sprite2.png"))
    {
        return EXIT_FAILURE;
    }
    sf::Texture texSprite3;
    if (!texSprite3.loadFromFile("rsc/sprite3.png"))
    {
        return EXIT_FAILURE;
    }
    sf::Texture texSprite4;
    if (!texSprite4.loadFromFile("rsc/sprite4.png"))
    {
        return EXIT_FAILURE;
    }
    sf::Texture texSprite5;
    if (!texSprite5.loadFromFile("rsc/sprite5.png"))
    {
        return EXIT_FAILURE;
    }
    sf::Texture texSprite6;
    if (!texSprite6.loadFromFile("rsc/sprite6.png"))
    {
        return EXIT_FAILURE;
    }
    /**
     * @brief load cpu texture in cpuMode sprite
     */
    sf::Sprite spriteWelcome(texWelcome);
    sf::Sprite sprite1(texSprite1);
    sf::Sprite sprite2(texSprite2);
    sf::Sprite sprite3(texSprite3);
    sf::Sprite sprite4(texSprite4);
    sf::Sprite sprite5(texSprite5);
    sf::Sprite sprite6(texSprite6);
    sf::Sprite spriteBack(texBack);

    /**
     * @brief clear the window and draw the welcome screen sprite
     */
	float y = 0;

	clk.restart();
	tme = clk.getElapsedTime();
	while (tme.asSeconds() < 5)
	{
		window->clear();
		window->draw(spriteBack);
		sprite1.setPosition(150.0, y + 100.0);
		sprite2.setPosition(600.0, y + 300.0);
		sprite3.setPosition(1000.0, y + 400.0);
		sprite4.setPosition(400.0, y + 600.0);
		sprite5.setPosition(800.0, y + 700.0);
		window->draw(sprite1);
		window->draw(sprite2);
		window->draw(sprite3);
		window->draw(sprite4);
		window->draw(sprite5);
		window->draw(spriteWelcome);
		window->display();
		tme = clk.getElapsedTime();
		y -= 0.1;
	}

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
        if(bOn==0 && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
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
        }
    }

    /**
     * @brief check while window is open
     */
}

int main(int, char const**){	
	renderWindow();
	gameMain();
}


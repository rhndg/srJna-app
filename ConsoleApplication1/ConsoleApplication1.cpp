// ConsoleApplication1.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "src/showSelect.cpp"

/**
 * @brief render a window
 * @details creates a new window using sf::RenderWindow
 *
 * @param w width
 * @param t height
 */
void renderWindow(){
    window = new sf::RenderWindow(sf::VideoMode(1366, 768), "srJna");
}

/**
 * @brief events after window is rendered
 */

int showWelcome(){
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
        sprite1.setPosition(100.0, y + 50.0);
        sprite2.setPosition(300.0, y + 400.0);
        sprite3.setPosition(500.0, y + 200.0);
        sprite4.setPosition(700.0, y + 700.0);
        sprite5.setPosition(900.0, y + 100.0);
        sprite6.setPosition(1100.0, y + 750);
        window->draw(sprite1);
        window->draw(sprite2);
        window->draw(sprite3);
        window->draw(sprite4);
        window->draw(sprite5);
		window->draw(sprite6);
        window->draw(spriteWelcome);
        window->display();
        tme = clk.getElapsedTime();
        y -= 0.1;
    }
}

int main(int, char const**){	
	renderWindow();
    showWelcome();
	showSelect();
}
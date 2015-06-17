#include "Helper.hpp"


int showWelcome(RenderWindow *window){
	Texture texBack,
		texWelcome,
		texSprite1,
		texSprite2,
		texSprite3,
		texSprite4,
		texSprite5,
		texSprite6;


	if (!texBack.loadFromFile("../data/background.png")
		|| !texWelcome.loadFromFile("../data/welcome.png")
		|| !texSprite1.loadFromFile("../data/sprite1.png")
		|| !texSprite2.loadFromFile("../data/sprite2.png")
		|| !texSprite3.loadFromFile("../data/sprite3.png")
		|| !texSprite4.loadFromFile("../data/sprite4.png")
		|| !texSprite5.loadFromFile("../data/sprite5.png")
		|| !texSprite6.loadFromFile("../data/sprite6.png"))
	{
		return EXIT_FAILURE;
	}

	Sprite spriteWelcome(texWelcome),
		sprite1(texSprite1),
		sprite2(texSprite2),
		sprite3(texSprite3),
		sprite4(texSprite4),
		sprite5(texSprite5),
		sprite6(texSprite6),
		spriteBack(texBack);

	float y = 0;

	Clock clk;
	clk.restart();
	Time tme = clk.getElapsedTime();
	while (tme.asSeconds() < 5)
	{
		window->clear();
		window->draw(spriteBack);
		sprite1.setPosition(100.0, 1.5*y + 50.0);
		sprite2.setPosition(300.0, 0.5*y + 400.0);
		sprite3.setPosition(500.0, y + 200.0);
		sprite4.setPosition(700.0, 2 * y + 700.0);
		sprite5.setPosition(900.0, y + 100.0);
		sprite6.setPosition(1100.0, 1.75*y + 750);
		window->draw(sprite1);
		window->draw(sprite2);
		window->draw(sprite3);
		window->draw(sprite4);
		window->draw(sprite5);
		window->draw(sprite6);
		window->draw(spriteWelcome);
		window->display();
		tme = clk.getElapsedTime();
		y -= 1;
	}
}

int showMenue(RenderWindow *window){
	Texture mainMenu;
	if (!mainMenu.loadFromFile("../data/select.png")){
		return EXIT_FAILURE;
	}
	Sprite spriteMenu(mainMenu);
	int choice = -1;
	while (window->isOpen()){
		Event evnt;
		window->clear();
		window->draw(spriteMenu);
		window->display();
		window->pollEvent(evnt);
		if (evnt.type == Event::MouseButtonReleased){
			if (evnt.mouseButton.button == Mouse::Left){
				int x = evnt.mouseButton.x, y = evnt.mouseButton.y;
				//INDEX set choice to selected option
				if ((x > 560 && x < 863) && (y>158 && y < 230)){
					choice = 0;
				}
				else if ((x > 560 && x < 863) && (y>248 && y < 320)){
					choice = 1;
				}
				else if ((x > 560 && x < 863) && (y>341 && y < 413)){
					choice = 2;
				}
				else if ((x > 560 && x < 863) && (y>433 && y < 505)){
					choice = 3;
				}
				else if ((x > 560 && x < 863) && (y>527 && y < 598)){
					choice = 4;
				}
				//QUIT closewindow; exit
				else if ((x > 560 && x < 863) && (y>628 && y < 700)){
					window->close();
				}
			}
		}
		else if (evnt.type == Event::Closed){
			window->close();
		}
	}
	return choice;
}
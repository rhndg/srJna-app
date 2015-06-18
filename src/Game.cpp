#include "Game.hpp"

Game::Game(){

}

Game::~Game(){

}

Game::Game(string path, sf::RenderWindow *wndw){
	tme = clk.getElapsedTime();
	window = wndw;
	parse(path);
}

int Game::parse(string path){
	ifstream inputFile;
	inputFile.open(path.c_str());
	inputFile >> back >> mcq;
	while (inputFile.good()){
		string imageSource;
		int x, y;
		inputFile >> imageSource;
		paths.push_back("../data/" + imageSource);
		inputFile >> x >> y;
		topLeft.push_back(pair<int, int>(x, y));
		inputFile >> x >> y;
		botRight.push_back(pair<int, int>(x, y));
		inputFile >> x >> y;
		isMCQ.push_back(x);
		Ans.push_back(y);
	}
}

void Game::delayTime(float f)
{
	clk.restart();
	tme = clk.getElapsedTime();
	while (tme.asSeconds() < f)
	{
		tme = clk.getElapsedTime();
	}
}

void Game::start(){

	int state = 0, score = 0;
	sf::Event evnt;
	sf::Texture backTex, mcqTex;
	backTex.loadFromFile("../data/" + back);
	mcqTex.loadFromFile("../data/" + mcq);
	sf::Sprite backSprt(backTex), mcqSprt(mcqTex);
	while (state != paths.size()){
		int choice = -1;
		sf::Texture tex;
		tex.loadFromFile(paths[state]);
		sf::Sprite sprt(tex);
		while (window->isOpen()){
			window->clear();

			if (isMCQ[state] == 0){
				window->draw(backSprt);
				window->draw(sprt);
				window->display();
				
				if (window->pollEvent(evnt)){
					if (evnt.type == sf::Event::Closed){
						window->close();
						exit(0);
					}
					else if (evnt.type == sf::Event::MouseButtonReleased){

						if (evnt.mouseButton.button == sf::Mouse::Left){
							int x = evnt.mouseButton.x, y = evnt.mouseButton.y;

							if ((x > 834 && x < 1073) && (y >642 && y < 708)){
								window->close();
								exit(0);
							}

							if ((x > topLeft[state].first && x < botRight[state].first) && (y > topLeft[state].second && y < botRight[state].second)){
								state++;
								break;
							}

							if ((x > 284 && x < 523) && (y >642 && y < 708)){
								state = -1;
								break;
							}
						}
						else if (evnt.mouseButton.button == sf::Mouse::Right){
							if (state > 0)
								state--;
							break;
						}
					}
				}
			}
			else{
				window->draw(mcqSprt);
				window->draw(sprt);
				if (choice >= 0){
					sf::Texture tex;
					tex.loadFromFile("../data/tick.png");
					sf::Sprite sprt(tex);
					sprt.setPosition(220, 250 + choice * 100);
					window->draw(sprt);
				}
				window->display();
				
				if (window->pollEvent(evnt)){
					if (evnt.type == sf::Event::MouseButtonReleased){
						if (evnt.mouseButton.button == sf::Mouse::Left){

							int x = evnt.mouseButton.x, y = evnt.mouseButton.y;

							if ((x > 218 && x < 1080) && (y > 340 && y < 410)){
								choice = 1;
							}

							if ((x > 218 && x < 1080) && (y > 440 && y < 510)){
								choice = 2;
							}

							if ((x > 218 && x < 1080) && (y > 540 && y < 610)){
								choice = 3;
							}

							if ((x > 218 && x < 1080) && (y > 640 && y < 710)){
								choice = 4;
							}

							if ((x > 1188 && x < 1335) && (y > 644 && y < 705)){
								if (Ans[state] == choice)
									score++;
								state++;
								break;
							}
						}
					}
				}
			}
		}
		delayTime(0.1);
		while (window->pollEvent(evnt)){}

		if (state<0)
			break;
	}
}
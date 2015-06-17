#include "Game.hpp"

Game::Game(){

}

Game::~Game(){

}

Game::Game(string path, sf::RenderWindow *wndw){
	parse(path);
	window = wndw;
}

int Game::parse(string path){
	ifstream inputFile;
	inputFile.open(path.c_str());
	while (inputFile.good()){
		string imageSource;
		int x, y;
		inputFile >> imageSource;
		sf::Texture tex;
		if (!tex.loadFromFile("../data/"+imageSource)){
			return EXIT_FAILURE;
		}
		sf::Sprite image(tex);
		slides.push_back(image);
		inputFile >> x >> y;
		topLeft.push_back(pair<int, int>(x, y));
		inputFile >> x >> y;
		botRight.push_back(pair<int, int>(x, y));
		inputFile >> x >> y;
		isMCQ.push_back(x);
		Ans.push_back(y);
	}
}

void Game::start(){
	int state = 0,score = 0;

	while (state != slides.size()){
		int choice = -1;
		while (window->isOpen()){
			sf::Event evnt;
			window->clear();
			window->draw(slides[state]);
			if (isMCQ[state] == 0){
				window->display();
				///////////////////////////////////////////////////////
				//TODO Chudoy poll
				window->pollEvent(evnt);
					//if EXIT close window;exit
				if (evnt.type == sf::Event::Closed){
					window->close();
				}
				else if (evnt.type == sf::Event::MouseButtonReleased){
					if (evnt.mouseButton.button == Mouse::Left){
						int x = evnt.mouseButton.x, y = evnt.mouseButton.y;
						if ((x > 834 x < 1073) && (y >642 && y < 708)){
							window->close();
						}
					}
				}
				//if right click  state--;break
				else if (evnt.type == sf::Event::MouseButtonReleased){
					if (evnt.mouseButton.button == Mouse::Right){
						state--;
						break;
					}
				}
				//if NEXT topLeft[state]; botRight[state]; state++; break
				else if (evnt.type == sf::Event::MouseButtonReleased){
					if (evnt.mouseButton.button == Mouse::Left){
						int x = evnt.mouseButton.x, y = evnt.mouseButton.y;
						if ((x > topLeft[state].first && x < botRight[state].first) && (y > topLeft[state].second && y < botRight[state].second)){
							state++;
							break;
						}
					}
				}
				//if MENU state = -1; break
				else if (evnt.type == sf::Event::MouseButtonReleased){
					if (evnt.mouseButton.button == Mouse::Left){
						int x = evnt.mouseButton.x, y = evnt.mouseButton.y;
						if ((x > 284 x < 523) && (y >642 && y < 708)){
							state = -1;
							break;
						}
					}
				}
				///////////////////////////////////////////////////
			}
			else{
				//draw radio button if choice is not -1
				window->display();
				//TODO Chudoy poll
				///////////////////////////////////////////////////////////////////////
				//if SELECT a choice then update choice
				window->pollEvent(evnt)
				if (evnt.type == sf::Event::MouseButtonReleased){
					if (evnt.mouseButton.button == Mouse::Left){
						int x = evnt.mouseButton.x, y = evnt.mouseButton.y;
						if ((x > 218 x < 1080) && (y > 340 && y < 410)){
							choice = 1;
							break;
						}
					}
				}
				if (evnt.type == sf::Event::MouseButtonReleased){
					if (evnt.mouseButton.button == Mouse::Left){
						int x = evnt.mouseButton.x, y = evnt.mouseButton.y;
						if ((x > 218 x < 1080) && (y > 440 && y < 510)){
							choice = 2;
							break;
						}
					}
				}
				if (evnt.type == sf::Event::MouseButtonReleased){
					if (evnt.mouseButton.button == Mouse::Left){
						int x = evnt.mouseButton.x, y = evnt.mouseButton.y;
						if ((x > 218 x < 1080) && (y > 540 && y < 610)){
							choice = 3;
							break;
						}
					}
				}
				if (evnt.type == sf::Event::MouseButtonReleased){
					if (evnt.mouseButton.button == Mouse::Left){
						int x = evnt.mouseButton.x, y = evnt.mouseButton.y;
						if ((x > 218 x < 1080) && (y > 640 && y < 710)){
							choice = 4;
							break;
						}
					}
				}
				
				//NEXT state++;update score Ans[state];break 

				if (evnt.type == sf::Event::MouseButtonReleased){
					if (evnt.mouseButton.button == Mouse::Left){
						int x = evnt.mouseButton.x, y = evnt.mouseButton.y;
						if ((x > 1188 x < 1335) && (y > 644 && y < 705)){
							if (Ans[state] == choice)
								score++;
							state++;
							break;
						}
					}
				}
				///////////////////////////////////////////////////////////////////////
			}
		}
		if (state<0)
			break;
	}
}
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
			window->clear();
			window->draw(slides[state]);
			if (isMCQ[state] == 0){
				window->display();
				//TODO Chudoy poll
				//if EXIT close window;exit
				//if MENUE state = -1; break
				//if NEXT topLeft[state]; botRight[state]; state++; break
				//if right click  state--;break
			}
			else{
				//draw radio button if choice is not -1
				window->display();
				//TODO Chudoy poll
				//if SELECT a choice then update choice
				//NEXT state++;update score Ans[state];break 
			}
		}
		if (state == -1)
			break;
	}
}
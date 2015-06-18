#ifndef GAME_H

#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Game{
private:
	sf::RenderWindow *window;
	vector <string> paths;
	vector <pair<int, int> > topLeft, botRight;
	vector <int> isMCQ, Ans;
public:
	Game();
	Game(string path, sf::RenderWindow *wndw);
	~Game();
	int parse(string path);
	void start();
};

#endif 
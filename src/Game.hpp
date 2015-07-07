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
	string back, mcq;
	sf::RenderWindow *window;
	sf::Clock clk;
	sf::Time tme;
	string Heading;
	int qNum;
	vector <string> paths;
	vector <pair<int, int> > topLeft, botRight;
	vector <int> isMCQ, Ans;
	int parse(string path);
	void delayTime(float f);
public:
	Game();
	Game(string heading, string path, sf::RenderWindow *wndw);
	~Game();
	void start();
};

#endif 
#include "Helper.hpp"
#include "Game.hpp"

using namespace sf;

int main(int argc,char** argv){
	RenderWindow *window;
	window = new RenderWindow(VideoMode(1366, 768), "srJna", Style::Fullscreen);
	window->setFramerateLimit(60);

	showWelcome(window);
	Game games[5];
	games[0] = Game("../schemes/Electricity.gme", window);
	games[1] = Game("../schemes/ForceAndWork.gme", window);
	games[2] = Game("../schemes/Optics.gme", window);
	games[3] = Game("../schemes/Biology.gme", window);
	games[4] = Game("../schemes/Maths.gme", window);

	while (true){
		games[showMenue(window)].start();
	}

	return 0;
}

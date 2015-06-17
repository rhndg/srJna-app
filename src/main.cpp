#include "Helper.hpp"
#include "Game.hpp"

using namespace sf;

int main(int argc,char** argv){
	RenderWindow *window;
	window = new RenderWindow(VideoMode(1366, 768), "srJna", Style::Fullscreen);
	window->setFramerateLimit(60);

	showWelcome(window);
	Game games[5];
	games[0].parse("../schemes/Electricity.gme");
	games[1].parse("../schemes/ForceAndWork.gme");
	games[2].parse("../schemes/Optics.gme");
	games[3].parse("../schemes/Biology.gme");
	games[4].parse("../schemes/Maths.gme");

	while (true){
		games[showMenue(window)].start();
	}

	return 0;
}

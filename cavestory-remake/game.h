#pragma once
//dont need header guards because of pragma once. Delete later
//#ifndef GAME_H_
//#define GAME_H_

struct SDL_Window;

class Game {
private:
	void eventLoop();
	void update();
	void draw();

	SDL_Window* window_;
public:
	Game();
	~Game();
};

//#endif //GAME_H_
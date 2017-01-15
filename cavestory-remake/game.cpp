#include "game.h"

namespace {
	const int kFps = 60;
}

Game::Game() {
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_ShowCursor(SDL_DISABLE);
	eventLoop();
}

Game::~Game() {
	SDL_Quit();
}

void Game::eventLoop() {
	Graphics graphics;
	SDL_Event event;

	//takes the first sprite (pos: 0,0 which is 32 x 32) from the bitmap in our resources folder
	sprite_.reset(new Sprite("resources/csspritesheet.bmp", 0, 0, 32, 32));
	bool running = true;
	while (running) {
		const int start_time_ms = SDL_GetTicks();
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_ESCAPE) {
					running = false;
				}
				break;
			default:
				break;
			}
		}

		update();
		draw(graphics);
		const int elapsed_time_ms = SDL_GetTicks() - start_time_ms;
		SDL_Delay(1000 / kFps - elapsed_time_ms);
	}
}

void Game::update() {

}

void Game::draw(Graphics& graphics) {
	sprite_->draw(graphics, 0, 0, 32, 32);
}
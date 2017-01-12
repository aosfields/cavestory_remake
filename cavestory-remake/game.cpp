#include "game.h"
#include "SDL.H"
#include "iostream"

namespace {
	const int kScreenWidth = 640;
	const int kScreenHeight = 480;
	const int kFps = 60;
}

Game::Game() {
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_ShowCursor(SDL_DISABLE);
	SDL_Surface* screenSurface_ = NULL;
	window_ = SDL_CreateWindow("Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, kScreenWidth, kScreenHeight, SDL_WINDOW_SHOWN);
	if (window_ == NULL) {
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
	}
	else {
		screenSurface_ = SDL_GetWindowSurface(window_);
		SDL_FillRect(screenSurface_, NULL, SDL_MapRGB(screenSurface_->format, 0xFF, 0xFF, 0xFF));
		SDL_UpdateWindowSurface(window_);
	}
	eventLoop();
}

Game::~Game() {
	SDL_DestroyWindow(window_);
	SDL_Quit();
}

void Game::eventLoop() {
	SDL_Event event;

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
		draw();
		const int elapsed_time_ms = SDL_GetTicks() - start_time_ms;
		SDL_Delay(1000 / kFps - elapsed_time_ms);
	}
}

void Game::update() {

}

void Game::draw() {

}
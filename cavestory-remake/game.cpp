#include "game.h"
#include "animated_sprite.h"

namespace 
{
	const int kFps = 60;
}

int Game::kTileSize = 32;

Game::Game() 
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_ShowCursor(SDL_DISABLE);
	eventLoop();
}

Game::~Game() 
{
	SDL_Quit();
}

void Game::eventLoop() 
{
	//Coming from Java this seemed a bit weird not instantiating the objects
	//but in C++ this means that object only lives on the stack, and not the heap
	//if I did Input input = new Input() it gets put on the heap :)!!
	Graphics graphics;
	SDL_Event event;
	Input input;

	//takes the first sprite (pos: 0,0 which is 32 x 32) from the bitmap in our resources folder
	//each frame lasts 15 fps and there are a total of 3 frames (EP3)
	sprite_.reset(new AnimatedSprite("resources/csspritesheet.bmp", 0, 0, kTileSize, kTileSize, 15, 3));
	
	bool running = true;
	int last_update_time = SDL_GetTicks();
	input.beginNewFrame();
	while (running) {
		const int start_time_ms = SDL_GetTicks();
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_KEYDOWN:
				input.keyDownEvent(event);
				//if (event.key.keysym.sym == SDLK_ESCAPE) {
				//	running = false;
				//}
				break;
			case SDL_KEYUP:
				input.keyUpEvent(event);
				break;
			default:
				break;
			}
		}

		if (input.wasKeyPressed(SDLK_ESCAPE)) {
			running = false;
		}

		const int current_time_ms = SDL_GetTicks();
		update(current_time_ms - last_update_time);
		last_update_time = current_time_ms;

		draw(graphics);
		const int elapsed_time_ms = SDL_GetTicks() - start_time_ms;
		SDL_Delay(1000 / kFps - elapsed_time_ms);
	}
}

void Game::update(int elapsed_time_ms) {
	sprite_->update(elapsed_time_ms);
}

void Game::draw(Graphics& graphics) {
	sprite_->draw(graphics, 0, 0, kTileSize, kTileSize);
}
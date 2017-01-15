#pragma once
#include "SDL.h"

class Graphics {
private:
	SDL_Window* window_;

	//SDL2 uses renders. From what I understand, it is essentially a pointer to the hidden buffer
	//http://stackoverflow.com/a/21007477
	//all functions manipulate the hidden buffer. SDL_RendererPresent() moves the buffer to the window
	//Similar to SDL 1.2's flip. 
	SDL_Renderer* renderer_;
public:
	Graphics();
	~Graphics();
	void createTextureAndRender(SDL_Surface* screensrc, 
		SDL_Rect* src_rectangle, SDL_Rect* dest_rectangle);
};
#include "graphics.h"

namespace {
	const int kScreenWidth = 640;
	const int kScreenHeight = 480;
	const int kFps = 60;
}

Graphics::Graphics() {
	window_ = SDL_CreateWindow("Cavestory Remake", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, kScreenWidth, kScreenHeight, SDL_WINDOW_SHOWN);
	renderer_ = SDL_CreateRenderer(window_, -1, 0);
}

Graphics::~Graphics() {
	SDL_DestroyWindow(window_);
}


//In episode 3, he creates two functions, Graphcis::blitSurface and Graphics::flip
//However SDL2 has removed the SDL_Flip function and now you must do something else to get 
//the back buffer to appear on screen. So I have merged blitsurface() and flip() into a single function.
//This was helpful in figuring out how to do the SDL_Flip https://wiki.libsdl.org/SDL_RenderCopy
void Graphics::createTextureAndRender(SurfaceID screensrc,
	SDL_Rect* src_rectangle, SDL_Rect* dest_rectangle) {
	SDL_Texture* texture_;

	//we have to create a texture to place in the renederer
	//https://wiki.libsdl.org/SDL_CreateTextureFromSurface
	texture_ = SDL_CreateTextureFromSurface(renderer_, screensrc);
	//Clear the renderer_ just in case
	
	//In episode 6 he had an issue where the graphics were getting
	//clipped when moving the sprite
	SDL_RenderClear(renderer_);
	//Copy the texture to the renderer and then present it.
	//SDL_RenderCopy(renderer_, texture_, src_rectangle, dest_rectangle);
	SDL_RenderCopy(renderer_, texture_, src_rectangle, dest_rectangle);

	SDL_RenderPresent(renderer_);
	
	//Destroy the texture since we don't need it anymore.
	SDL_DestroyTexture(texture_);
}

//need to scope in the typedef we made in graphics.h for the return type
Graphics::SurfaceID Graphics::loadImage(const std::string & file_path)
{
	//if we have not loaded in the spritesheet
	if (sprite_sheets_.count(file_path) == 0) {
		//load it in now
		sprite_sheets_[file_path] = SDL_LoadBMP(file_path.c_str());
	}
	return sprite_sheets_[file_path];
}

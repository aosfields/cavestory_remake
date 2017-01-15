#pragma once
#include <string>
#include "SDL.h"
#include "graphics.h"

class Sprite {
public:
	Sprite(const std::string& file_path,
			int source_x, int source_y,
			int width, int height);
	~Sprite();

	void draw(Graphics& graphics, int x, int y, int w, int h);

private:
	SDL_Surface* sprite_sheet_;
	SDL_Rect source_rect_;
};


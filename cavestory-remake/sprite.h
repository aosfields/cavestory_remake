#pragma once
#include <string>
#include "SDL.h"
#include "graphics.h"

class Sprite {
public:
	Sprite(Graphics& graphics, const std::string& file_path,
			int source_x, int source_y,
			int width, int height);
	virtual ~Sprite();

	virtual void update(int /*elapsed_time_ms*/) {}
	void draw(Graphics& graphics, int x, int y, int w, int h);

protected:
	SDL_Rect source_rect_;

private:
	SDL_Surface* sprite_sheet_;
};


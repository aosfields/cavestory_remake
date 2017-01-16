#include "sprite.h"


Sprite::Sprite(Graphics& graphics, const std::string& file_path,
	int source_x, int source_y,
	int width, int height) {

	//This function takes a char* and not a string. 
	//Have to convert it via c_str() function
	sprite_sheet_ = graphics.loadImage(file_path);
	
	//Where to look in the sheet for the sprite.
	source_rect_.x = source_x;
	source_rect_.y = source_y;
	source_rect_.w = width;
	source_rect_.h = height;
}


Sprite::~Sprite() {
	SDL_FreeSurface(sprite_sheet_);
}


//In Episode 3, he doens't include w and h for arguments because the SDL_Blitsurface
//apparently didn't care about the dst rectangles w/h. However what I found was that the
//SDL_Renderer does care about them (image didn't show when I left them out) so I modified
//the function to take them.
void Sprite::draw(Graphics& graphics, int x, int y, int w, int h) {
	SDL_Rect dst_rectangle;
	dst_rectangle.x = x;
	dst_rectangle.y = y;
	dst_rectangle.w = w;
	dst_rectangle.h = h;

	/*According to the documentation here: 
	*https://wiki.libsdl.org/SDL_BlitSurface
	*"Only the position is used in the dstrect 
	*(the width and height are ignored)."
	*/
	graphics.createTextureAndRender(sprite_sheet_, &source_rect_, &dst_rectangle);
}

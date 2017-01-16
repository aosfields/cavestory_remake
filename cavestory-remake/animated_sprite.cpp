#include "animated_sprite.h"
#include "game.h" 


//The colon after the constructor signifies an initializer list
//We are initializing the base class, and the consts we didn't initialize in the header file
//Here is some reasons as to why we can do this https://stackoverflow.com/questions/355258/why-must-const-members-be-initialized-in-the-constructor-initializer-rather-than
AnimatedSprite::AnimatedSprite(Graphics& graphics, const std::string& file_path,
	int source_x, int source_y,
	int width, int height,
	int fps, int num_frames) :
	Sprite(graphics, file_path, source_x, source_y, width, height),
	frame_time_(1000 / fps),
	num_frames_(num_frames),
	current_frame_(0),
	elapsed_time_(0)
{
}

void AnimatedSprite::update(int elapsed_time_ms) {
	elapsed_time_ += elapsed_time_ms;

	if (elapsed_time_ > frame_time_) {
		++current_frame_;
		elapsed_time_ = 0;
		if (current_frame_ < num_frames_) {
			//tilesize is 32 for this bitmap file
			source_rect_.x += Game::kTileSize;
		}
		else {
			//Move the source rect to the beginning of the bitmap section to restart the cycle
			//Why " - 1"? If tile size is 1, we are only moving by 1 each time. Frame 1 starts at x = 0
			//Frame 2 starts at x = 1, etc. If we have a total of 3 frames, and we are on Frame 3 then
			// x = 2, if we subtract by 1*3, we would end up at x = -1, which doesnt exist in our bitmap
			//we want to return to the starting position of frame 1 which is x = 0. :D
			source_rect_.x -= Game::kTileSize*(num_frames_ - 1);
			current_frame_ = 0;
		}
	}
}
AnimatedSprite::~AnimatedSprite()
{
}

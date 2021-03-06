#pragma once
#include "sprite.h"

class AnimatedSprite : public Sprite
{
public:
	//for an Animated sprite we need to know the fps and
	//total number of frames that sprite has
	AnimatedSprite(Graphics& graphics, const std::string& file_path,
		int source_x, int source_y,
		int width, int height, 
		int fps, int num_frames);
	~AnimatedSprite();

	void update(int elapsed_time_ms);

private:
	const int frame_time_;
	const int num_frames_;
	int current_frame_;
	int elapsed_time_; //Elapsed time since the last frame change
};


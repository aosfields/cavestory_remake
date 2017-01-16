#pragma once
//I had a recursive header issue in EP6 so i decided
//to add back the headerguards.
#ifndef GAME_H_
#define GAME_H_

#include "SDL.H"
#include "iostream"
#include "graphics.h"
#include "player.h"
#include "sprite.h"
#include "input.h"
//Look at installing_boost file to figure out how
//to add boost
#include <boost/scoped_ptr.hpp>

//According to the tutorial, this wil allow us to use smart pointers
//which are smart enough to know when to delete themselves.
class Game {
private:
	void eventLoop();
	void update(int elapsed_time_ms);
	void draw(Graphics &graphics);
	
	//scoped_ptr is the simplest. When it goes out of scope, it is destroyed. The following code is illegal (scoped_ptrs are non-copyable) but will illustrate a point:
	//Because this pointer is in the Game Class Scope, whenever we deconstruct the Game object, the pointer should also be deallocated. Yay~!
	
	boost::scoped_ptr<Player> player_;
	
public:
	Game();
	~Game();
	static int kTileSize;
};

#endif //GAME_H_
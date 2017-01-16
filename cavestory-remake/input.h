#pragma once

#include <map>
#include "SDL.h"

class Input
{

public:
	Input();
	~Input();
	void beginNewFrame();
	void keyUpEvent(const SDL_Event& event);
	void keyDownEvent(const SDL_Event& event);

	bool wasKeyPressed(SDL_Keycode key);
	bool wasKeyReleased(SDL_Keycode key);
	bool isKeyHeld(SDL_Keycode key);

private:
	std::map<SDL_Keycode, bool> held_keys_;
	std::map<SDL_Keycode, bool> pressed_keys_;
	std::map<SDL_Keycode, bool> released_keys_;
};


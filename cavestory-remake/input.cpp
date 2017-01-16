#include "input.h"


Input::Input()
{
}


Input::~Input()
{
}

//At the beginning of each frame, clear the keys in
//pressed and released maps
void Input::beginNewFrame()
{
	pressed_keys_.clear();
	released_keys_.clear();
}

void Input::keyUpEvent(const SDL_Event& event)
{
	released_keys_[event.key.keysym.sym] = true;
	held_keys_[event.key.keysym.sym] = false;
}

void Input::keyDownEvent(const SDL_Event& event)
{
	pressed_keys_[event.key.keysym.sym] = true;
	held_keys_[event.key.keysym.sym] = true;
}

bool Input::wasKeyPressed(SDL_Keycode key)
{
	return pressed_keys_[key];
}

bool Input::wasKeyReleased(SDL_Keycode key)
{
	return released_keys_[key];
}

bool Input::isKeyHeld(SDL_Keycode key)
{
	return held_keys_[key];
}

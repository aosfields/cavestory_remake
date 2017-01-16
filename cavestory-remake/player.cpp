#include "player.h"
#include "game.h"
#include <algorithm>
#include <iostream>

namespace {
	//factor for when slowing down. We dont want to slow down abruptly
	//we want to go down slowly until we reach zero.
	const float kSlowdownFactor = 0.8f;

	//value c.herbert from the tutorial found to be pretty good for walking
	const float kWalkingAcceleration = 0.0012f; // pixels / ms / ms
	
	const float kMaxSpeedX = 0.325f; // pixels / ms
}

Player::Player(Graphics& graphics, int x, int y) :
		x_(x), y_(y), velocity_x_(0.0f),
		acceleration_x_(0.0f)
{
	//takes the first sprite (pos: 0,0 which is 32 x 32) from the bitmap in our resources folder
	//each frame lasts 15 fps and there are a total of 3 frames (EP3)
	sprite_.reset( new AnimatedSprite(graphics,
		"resources/csspritesheet.bmp", 0, 0,
		Game::kTileSize, Game::kTileSize, 15, 3));
}

Player::~Player()
{
}

void Player::update(int elapsed_time_ms)
{
	sprite_->update(elapsed_time_ms);
	
	//because multiplying with an int will truncate the float
	x_ += round(velocity_x_ * elapsed_time_ms);
	velocity_x_ += acceleration_x_ * elapsed_time_ms;
	//making sure v_x never goes above the max speed
	if (acceleration_x_ < 0.0f) {
		velocity_x_ = std::max(velocity_x_, -kMaxSpeedX);
	} else if (acceleration_x_ > 0.0f) {
		velocity_x_ = std::min(velocity_x_, kMaxSpeedX);
	} else {
		velocity_x_ *= kSlowdownFactor;
	}
}

void Player::draw(Graphics& graphics)
{
	sprite_->draw(graphics, x_, y_, Game::kTileSize, Game::kTileSize);
}

void Player::startMovingLeft()
{
	acceleration_x_ = -kWalkingAcceleration;
}

void Player::startMovingRight()
{
	acceleration_x_ = kWalkingAcceleration;
}

void Player::stopMoving()
{
	acceleration_x_ = 0.0f;
}

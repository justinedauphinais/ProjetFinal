#pragma once

#include "drawable.h"

class torch : public drawable {
private:
	vector<Texture> _animation;
	int _animationIterator;

public:
	torch(gameDataRef data, float posX, float posY, int animationIterator);

	void update(float dt);
};
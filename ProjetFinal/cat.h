#pragma once

#include "entity.h"

class cat : public entity {
private:


public:
	cat(gameDataRef data);

	void update(float dt);
};
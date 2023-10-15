#pragma once
#include "Engine.h"

class Spikes {
public:
	Spikes();
	~Spikes();

	void init();
	void update();
	void draw();
	void destroy();

	SDL_Texture* txt;
};
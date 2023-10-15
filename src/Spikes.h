#pragma once
#include "Engine.h"

class Spikes {
public:
	Spikes();
	~Spikes();

	void init(int, int, int, int, int);
	void update();
	void draw();
	void destroy();

	SDL_Texture* txt;
	SDL_Rect pos;
	SDL_Rect hitbox;
	int dir;

	static const int SPIKE_WIDTH = 64;
	static const int SPIKE_HEIGHT = 64;
};
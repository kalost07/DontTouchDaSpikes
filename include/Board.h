#pragma once

#include "Bird.h"
#include "Spikes.h"
#include <vector>

class Board 
{
public:
	Board();
	~Board();

	void init();
	void update();
	void draw();
	void destroy();

	Bird bird;
	Bird bird2;

	SDL_Rect c_rect;
	SDL_Texture* c_text;
	vector<Spikes> spikes;

	void c_generate();
	void c_delete();
	void c_draw();

	int score = 0;
	bool dir = 0;
	int timer = 20;
	

	void make_spikes(int);

private:

};
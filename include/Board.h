#pragma once

#include "Bird.h"

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

	SDL_Rect c_rect;
	SDL_Texture* c_text;
	

	void c_generate();
	void c_delete();
	void c_draw();

private:

};
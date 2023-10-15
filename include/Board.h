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

private:

};
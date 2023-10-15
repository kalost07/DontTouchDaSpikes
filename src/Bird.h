#include "Engine.h"

class Bird {
	Bird();
	~Bird();

	void init();
	void update();
	void draw();
	void destroy();

	SDL_Rect pos;
	float2 velocity;

};
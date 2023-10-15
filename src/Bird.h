#include "Engine.h"

class Bird {
public:
	Bird();
	~Bird();

	void init();
	void update();
	void draw();
	void destroy();

	static const int BIRD_WIDTH = 128;
	static const int BIRD_HEIGHT = 128;

	SDL_Rect pos;
	float2 velocity;

	SDL_Texture* txt;
	bool jumping;
	int cooldown = 0;
	int temo;
	void jump();
};
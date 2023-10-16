#include "Engine.h"

class Bird {
public:
	Bird();
	~Bird();

	void init(SDL_Scancode,int,int);
	void update();
	void draw();
	void destroy();

	static const int BIRD_WIDTH = 128;
	static const int BIRD_HEIGHT = 128;
	static const int BIRD_HITBOX_WIDTH = 92;
	static const int BIRD_HITBOX_HEIGHT = 92;

	SDL_Rect pos;
	SDL_Rect hitbox;
	float2 velocity;
	SDL_Rect hitbox;

	SDL_Texture* txt;
	int sprite;

	bool jumping;
	int cooldown = 0;
	SDL_Scancode control;
	
	void jump();
	SDL_Rect calc_hitbox();
};
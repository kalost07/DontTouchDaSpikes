#include "World.h" 
#include <time.h>
#include <cstdlib>

#undef main

World world;

static Uint32 next_time;
static const int TICK_INTERVAL = 1000 / FPS;

Uint32 time_left()
{
	Uint32 now;

	now = SDL_GetTicks();
	if (next_time <= now) return 0;
	else return next_time - now;
}

int main(int* argc, char* argv[])
{
	srand(time(NULL));
	world.init();
	next_time = SDL_GetTicks() + TICK_INTERVAL;
	while (world.isRunning())
	{
		world.run();
		SDL_Delay(time_left());
		next_time+=TICK_INTERVAL;
	}

	return 0;
}
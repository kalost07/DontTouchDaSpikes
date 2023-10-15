#include "Bird.h"

Bird::Bird()
{
}

Bird::~Bird()
{
}

void Bird::init()
{
}

void Bird::update() {
	velocity.y -= GRAVITY / FPS;
	pos.x += velocity.x;
	pos.y += velocity.y;
}

void Bird::draw()
{
}

void Bird::destroy()
{
}

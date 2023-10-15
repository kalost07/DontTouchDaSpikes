#include "Bird.h"
#include "Presenter.h"
#include "InputManager.h"

Bird::Bird()
{
}

Bird::~Bird()
{
}

void Bird::init() {
	txt = loadTexture("double_pile.bmp");
	cout << txt << endl;
	jumping = false;
	pos = { 300,900,BIRD_WIDTH,BIRD_HEIGHT };
	velocity = { 10,0 };
}

void Bird::update() {
	velocity.y += GRAVITY/FPS;
	pos.x += velocity.x;
	pos.y += velocity.y;
	cooldown--;
	if (cooldown < 5 ) jumping = false;
	if (cooldown < 0) cooldown = 0;
	if (cooldown == 0 && InputManager::m_keyboardState[SDL_SCANCODE_SPACE]) jump();
}

void Bird::draw()
{
	Drawable tmp;
	tmp.texture = txt;
	tmp.drect = pos;
	tmp.srect = { jumping * 32,0,32,32 };
	tmp.angle = atan2(velocity.y, velocity.x) * 180 / 3.14;

	if (velocity.x > 0) {
		tmp.flip = SDL_FLIP_NONE;
	}
	else {
		tmp.flip = SDL_FLIP_VERTICAL;
	}

	drawObject(tmp);
}

void Bird::destroy()
{
	SDL_DestroyTexture(txt);
}

void Bird::jump()
{
	cooldown = 20;
	jumping = true;
	velocity.y = -15;
}

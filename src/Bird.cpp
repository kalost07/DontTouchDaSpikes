#include "Bird.h"
#include "Presenter.h"
#include "InputManager.h"

Bird::Bird()
{
}

Bird::~Bird()
{
}

void Bird::init(SDL_Scancode ctrl, int dir, int spr) {
	control = ctrl;
	txt = loadTexture("double_pile.bmp");
	jumping = false;
	pos = { 910,540 - BIRD_HEIGHT / 2,BIRD_WIDTH,BIRD_HEIGHT};
	velocity = { float(10 * dir),0 };
	hitbox = calc_hitbox();
	sprite = spr;
}

void Bird::update() {
	velocity.y += GRAVITY/FPS;
	pos.x += velocity.x;
	pos.y += velocity.y;
	cooldown--;
	if (cooldown < 5 ) jumping = false;
	if (cooldown < 0) cooldown = 0;
	if (cooldown == 0 && InputManager::m_keyboardState[control]) jump();
	hitbox = calc_hitbox();
}

void Bird::draw()
{
	Drawable tmp;
	tmp.texture = txt;
	tmp.drect = pos;
	tmp.srect = { jumping * 128,sprite * 128,128,128 };
	tmp.angle = atan2(velocity.y, velocity.x) * 180 / 3.14;

	if (velocity.x > 0) {
		tmp.flip = SDL_FLIP_NONE;
	}
	else {
		tmp.flip = SDL_FLIP_VERTICAL;
	}
	drawObject(tmp);
	if (DEBUG) {
		SDL_SetRenderDrawColor(Presenter::m_main_renderer, 255, 0, 0, 1);
		SDL_RenderDrawRect(Presenter::m_main_renderer, &hitbox);
	}
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

SDL_Rect Bird::calc_hitbox()
{
	SDL_Rect tmp = pos;
	tmp.x += (BIRD_WIDTH - BIRD_HITBOX_WIDTH) / 2;
	tmp.y += (BIRD_HEIGHT - BIRD_HITBOX_HEIGHT) / 2;
	tmp.w = BIRD_HITBOX_WIDTH;
	tmp.h = BIRD_HITBOX_HEIGHT;
	return tmp;
}

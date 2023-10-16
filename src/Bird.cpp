#include "Bird.h"
#include "Presenter.h"
#include "InputManager.h"

Bird::Bird()
{
}

Bird::~Bird()
{
}

void Bird::init(SDL_Scancode ctrl,int dir) {
	control = ctrl;
	txt = loadTexture("double_pile.bmp");
	cout << txt << endl;
	jumping = false;
	pos = { 930-BIRD_WIDTH/2+dir*64,540-BIRD_HEIGHT/2,BIRD_WIDTH,BIRD_HEIGHT };
	velocity = { float(10*dir),0 };
	hitbox = pos;
	hitbox.x += 7;
	hitbox.y += 7;
	hitbox.w -= 14;
	hitbox.h -= 14;
}

void Bird::update() {
	velocity.y += GRAVITY/FPS;
	pos.x += velocity.x;
	hitbox.x += velocity.x;
	pos.y += velocity.y;
	hitbox.y += velocity.y;
	cooldown--;
	if (cooldown < 5 ) jumping = false;
	if (cooldown < 0) cooldown = 0;
	if (cooldown == 0 && InputManager::m_keyboardState[control]) jump();
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

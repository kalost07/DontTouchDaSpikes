#include "Spikes.h"
#include "Presenter.h"

Spikes::Spikes()
{
}

Spikes::~Spikes()
{
}

void Spikes::init(int x,int y,int w,int h,int dirt) {
	pos = { x,y,w,h };
	hitbox = pos;
	hitbox.x -= 2;
	hitbox.y -= 2;
	hitbox.w -= 4;
	hitbox.h -= 4;
	txt = loadTexture("up_spike.bmp");
	dir = dirt;
}

void Spikes::update()
{

}

void Spikes::draw()
{
	Drawable tmp;
	tmp.srect = { 0,0,32,32 };
	tmp.texture = txt;
	tmp.angle = dir * 90;
	for (int i = 0; i < pos.w; i += SPIKE_WIDTH) {
		for (int j = 0; j < pos.h; j += SPIKE_HEIGHT) {
			tmp.drect = { pos.x + i,pos.y + j,SPIKE_WIDTH,SPIKE_HEIGHT };
			drawObject(tmp);
		}
	}
}

void Spikes::destroy()
{
	SDL_DestroyTexture(txt);
}

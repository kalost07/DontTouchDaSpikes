#include "Board.h"
#include "Presenter.h"

Board::Board()
{
}

Board::~Board()
{
}

void Board::init()
{
	bird.init(SDL_SCANCODE_SPACE,1);
	if (multiplayer) bird2.init(SDL_SCANCODE_RETURN, -1); // control with enter
	Spikes spike;
	spikes.push_back(spike);
	spikes.push_back(spike);
	spikes.push_back(spike);
	spikes.push_back(spike);
	spikes[0].init(0, 896, 1920, 64, 0);
	spikes[1].init(0, 0, 1920, 64, 2);

}

void Board::update()
{
	
	if (multiplayer) {
		bird.update();
		if (bird.pos.x > 1920 - bird.BIRD_WIDTH || bird.pos.x < 0) {
			bird.velocity.x *= -1;
			bird2.velocity.x *= -1;
			c_delete();
			c_generate();
			spikes.erase(spikes.begin() + 2, spikes.end());
			make_spikes(0);
			make_spikes(1);
		}
		bird2.update();
	}
	else {
		bird.update();
		if (bird.pos.x > 1920 - bird.BIRD_WIDTH || bird.pos.x < 0) {
			bird.velocity.x *= -1;
			c_delete();
			c_generate();
			spikes.erase(spikes.begin() + 2, spikes.begin() + 4);
			make_spikes(dir);
			dir = !dir;
		}
	}
	if (collRectRect( c_rect,  bird.pos)){
		c_delete();
		score++;
	}
	if (multiplayer) {
		if (collRectRect(c_rect, bird2.pos)) {
			c_delete();
			score++;
		}
	}
	// spikes collision with pile
	for (int i = 0; i < spikes.size(); i++) {
		if (collRectRect(spikes[i].hitbox, bird.pos)) {
			cout << "hit\n";
		}
	}
	if (multiplayer) {
		for (int i = 0; i < spikes.size(); i++) {
			if (collRectRect(spikes[i].hitbox, bird2.pos)) {
				cout << "hit\n";
			}
		}
	}
}

void Board::draw()
{
	bird.draw();
	if (multiplayer) bird2.draw();
	c_draw();
	for (int i = 0; i < spikes.size(); i++) {
		spikes[i].draw();
	}
	
}

void Board::destroy()
{
	bird.destroy();
	bird2.destroy();
}

void Board::c_generate()
{
	c_text = loadTexture("candy.bmp");
	c_rect.x = rand() % 960 + 480;
	c_rect.y = rand() % 520 + 270;
	c_rect.w = 128;
	c_rect.h = 128;
	
}

void Board::c_draw() {
	Drawable tmp;
	tmp.flip = SDL_FLIP_NONE;
	tmp.drect = c_rect;
	tmp.texture = c_text;
	tmp.srect = {0,0,32,32};
	drawObject(tmp);
}

void Board::make_spikes(int side)
{
	int safe = rand() % 10;
	cout << safe << endl;
	Spikes tmp;
	spikes.push_back(tmp);
	spikes.back().init(side * (1920 - 64), 64, 64, safe * 64, 1+2*side);
	spikes.push_back(tmp);
	spikes.back().init(side * (1920 - 64), 256+safe*64, 64, (10-safe)*64, 1+2*side);
}

void Board::c_delete()
{
	SDL_DestroyTexture(c_text);
}

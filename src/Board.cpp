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
	bird.init();
}

void Board::update()
{
	bird.update();
	if (bird.pos.x > 1920-bird.BIRD_WIDTH || bird.pos.x < 0) {
		bird.velocity.x *= -1;
		c_delete();
		c_generate();
	}
}

void Board::draw()
{
	bird.draw();
	c_draw();
	
}

void Board::destroy()
{
	bird.destroy();
}

void Board::c_generate()
{
	c_text = loadTexture("candy.bmp");
	cout << c_text;
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

void Board::c_delete()
{
	SDL_DestroyTexture(c_text);
}

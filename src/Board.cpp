#include "Board.h"

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

		

		

	}
}

void Board::draw()
{
	bird.draw();
	
}

void Board::destroy()
{
	bird.destroy();
}

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
}

void Board::draw()
{
	bird.draw();
}

void Board::destroy()
{
	bird.destroy();
}

#include "World.h"

World::World()
{
	m_isRunning = true;
}

World::~World()
{
}

void World::init()
{
	m_presenter.init();
	board.init();
	m_inputManager.handleInput();
	board.update();
	m_presenter.draw();
	while (!m_inputManager.anyKeyIsPressed()) {
	m_inputManager.handleInput();

	}
}

void World::run()
{
	m_inputManager.handleInput();
	board.update();
	m_presenter.draw();
}

// call destroy for all classes to prevent memory leak
void World::destroy()
{
	SDL_DestroyRenderer(m_presenter.m_main_renderer);

	SDL_DestroyWindow(m_presenter.m_main_window);
}

bool World::isRunning()
{
	return m_isRunning;
}

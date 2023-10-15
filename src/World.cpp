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
	menu.init_all();

	game_state = 0;
	/*m_inputManager.handleInput();
	board.update();
	m_presenter.draw();
	while (!m_inputManager.anyKeyIsPressed()) {
	m_inputManager.handleInput();

	}
	*/
}

void World::run()
{
	m_inputManager.handleInput();
	m_presenter.draw();
	if (game_state == 0) {
		
		if (m_inputManager.m_mouseIsPressed) {
			if (MouseIsInRect(m_inputManager.m_mouseCoor, menu.m_quit_rect)) {
				//quit
			}
			if (MouseIsInRect(m_inputManager.m_mouseCoor, menu.m_2players_rect)) {
				game_state = 2;
			}
			if (MouseIsInRect(m_inputManager.m_mouseCoor, menu.m_1players_rect)) {
				game_state = 1;
				m_inputManager.handleInput();
				board.update();
				m_presenter.draw();
				while (!m_inputManager.anyKeyIsPressed()) {
					m_inputManager.handleInput();
				}
			}
		}
	}
	if (game_state == 1) {
		
		board.update();
	}
	if (game_state == 2) {
		//multiplayer

	}
	
	
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

#pragma once

#include "start_menu.h"
#include "Presenter.h"
#include "InputManager.h"
#include "Board.h"

class World
{
public:
	World();
	~World();

	Presenter m_presenter;
	InputManager m_inputManager;
	Board board;

	void init();
	void run();
	void destroy();

	Menu menu;

	bool isRunning();

	int game_state = 0;
private:
	bool m_isRunning;
};
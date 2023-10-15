#pragma once
#include "Engine.h"

class Menu {
public:
	SDL_Rect m_background_rect;
	SDL_Texture* m_background_texture;

	SDL_Rect m_title_rect;
	SDL_Texture* m_title_texture;

	SDL_Rect m_2players_rect;
	SDL_Texture* m_2players_texture;
	SDL_Rect m_1players_rect;
	SDL_Texture* m_1players_texture;

	SDL_Rect m_quit_rect;
	SDL_Texture* m_quit_texture;

	void init_quit();
	void init_title();
	void init_2players();
	void init_1players();
	void init_background();

	void init_all();

	void draw_quit();
	void draw_title();
	void draw_2players();
	void draw_1players();
	void draw_background();

	void draw_all();
};
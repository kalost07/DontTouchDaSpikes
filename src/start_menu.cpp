#include "start_menu.h"
#include "Presenter.h"

void Menu::init_quit()
{
	m_quit_rect.x = 1240;
	m_quit_rect.y = 600;
	m_quit_rect.w = 400;
	m_quit_rect.h = 200;
	m_quit_texture = loadTexture("quit.bmp");
}

void Menu::init_title()
{
	m_title_rect.w = 1000;
	m_title_rect.x = (1920- m_title_rect.w) / 2;
	m_title_rect.y = 100;
	m_title_rect.h = 500;
	m_title_texture = loadTexture("main_title.bmp");
}

void Menu::init_2players()
{
	m_2players_rect.x = 840;
	m_2players_rect.y = 600;
	m_2players_rect.w = 400;
	m_2players_rect.h = 200;
	m_2players_texture = loadTexture("multiplayer.bmp");
}

void Menu::init_1players()
{
	m_1players_rect.x = 440;
	m_1players_rect.y = 600;
	m_1players_rect.w = 400;
	m_1players_rect.h = 200;
	m_1players_texture = loadTexture("Singleplayer.bmp");
}
void Menu::init_background()
{
	m_background_rect.x = 0;
	m_background_rect.y = 0;
	m_background_rect.w = 1920;
	m_background_rect.h = 1080;
	m_background_texture = loadTexture("background.bmp");
}

void Menu::init_all()
{
	init_background();
	init_quit();
	init_2players();
	init_1players();
	init_title();
}

void Menu::draw_quit()
{
	Drawable tmp;
	tmp.texture = m_quit_texture;
	tmp.drect = m_quit_rect;

	tmp.srect = { 0,0,m_quit_rect.w,m_quit_rect.h };
	drawObject(tmp);
}

void Menu::draw_title()
{
	Drawable tmp;
	tmp.texture = m_title_texture;
	tmp.drect = m_title_rect;

	tmp.srect = {0,0,m_title_rect.w,m_title_rect.h};
	drawObject(tmp);
}

void Menu::draw_2players()
{
	Drawable tmp;
	tmp.texture = m_2players_texture;
	tmp.drect = m_2players_rect;

	tmp.srect = { 0,0,m_2players_rect.w,m_2players_rect.h };
	drawObject(tmp);
}

void Menu::draw_1players()
{
	Drawable tmp;
	tmp.texture = m_1players_texture;
	tmp.drect = m_1players_rect;
	tmp.srect = { 0,0,m_1players_rect.w,m_1players_rect.h };
	drawObject(tmp);
}

void Menu::draw_background()
{
	Drawable tmp;
	tmp.texture = m_background_texture;
	tmp.drect = m_background_rect;
	tmp.srect = { 0,0,m_background_rect.w,m_background_rect.h };
	drawObject(tmp);
}

void Menu::draw_all()
{
	draw_background();
	draw_2players();
	draw_1players();
	draw_quit();
	draw_title();
}

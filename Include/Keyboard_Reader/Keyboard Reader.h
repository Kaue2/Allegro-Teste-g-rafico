#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#pragma once

class Keyboard_Reader
{
public:
	ALLEGRO_USTR *buffer;

	Keyboard_Reader();
	void read_keys(int keycode, bool *exit, ALLEGRO_FONT *font);
	void add_char(int letter);
	void remove_char();
	void draw_buffer(int pos_x, int pos_y, ALLEGRO_USTR* message, ALLEGRO_FONT *font);
	void clear_screen_buffer();

};

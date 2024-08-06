#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#pragma once

class Keyboard_Reader
{
public:
	char buffer[100];

	Keyboard_Reader();
	void read_keys(int keycode, bool *exit, ALLEGRO_FONT *font, bool* shift_mode_pointer);
	void add_char(int letter, bool* shift_mode_pointer);
	void remove_char();
	void draw_buffer(int pos_x, int pos_y, char *message, ALLEGRO_FONT *font);
	void clear_screen_buffer();
	int get_final() const;


private:
	int length;
};

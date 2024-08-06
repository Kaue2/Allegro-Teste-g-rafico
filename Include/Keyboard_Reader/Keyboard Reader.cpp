#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <string>
#include <iostream>
#include "Keyboard Reader.h"
#include "../Colors/Colors.h"

Colors colors = Colors();

Keyboard_Reader::Keyboard_Reader()
{
	length = 0;
}

void Keyboard_Reader::read_keys(int keycode, bool *exit, ALLEGRO_FONT *font, bool* shift_mode_pointer)
{
	switch (keycode)
	{
	case ALLEGRO_KEY_ESCAPE:
		*exit = true;
		break;
	case ALLEGRO_KEY_BACKSPACE:
		remove_char();
		std::cout << "Quantidade de elementos: " << this->length << std::endl;
		std::cout << this->buffer << std::endl;
		break;
	case ALLEGRO_KEY_SPACE:
		*shift_mode_pointer = false;
		add_char(-64, shift_mode_pointer);
		break;
	default:
		add_char(keycode, shift_mode_pointer);
		std::cout << "final: " << this->length << std::endl;
		std::cout << this->buffer << std::endl;
		break;
	}
	clear_screen_buffer();
	draw_buffer(-500, -450, this->buffer, font);
}

void Keyboard_Reader::add_char(int letter, bool* shift_mode_pointer)
{
	if (this->length >= 99) {
		std::cout << "Buffer está cheio" << std::endl;
		return;
	}
	if (*shift_mode_pointer) {
		letter += 64;
		*shift_mode_pointer = false;
	}
	else
		letter += 96;

	buffer[this->length++] = letter;
}

int Keyboard_Reader::get_final() const
{
	return this->length;
}

void Keyboard_Reader::remove_char()
{
	if (length == 0) {
		std::cout << "O buffer está vazio" << std::endl;
		return;
	}
	this->buffer[--length] = '\0';
}

void Keyboard_Reader::draw_buffer(int pos_x, int pos_y, char* message, ALLEGRO_FONT *font)
{
	al_draw_text(font, al_map_rgb(255,255,255), pos_x, pos_y, NULL, message);
}

void Keyboard_Reader::clear_screen_buffer()
{
	al_draw_filled_rectangle(-500, -450, this->length * 15 - 500, -423, colors.gray);
}

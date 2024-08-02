#include "Keyboard Reader.h"
#include <string>
#include <iostream>

Keyboard_Reader::Keyboard_Reader() :
	buffer(),
	length(0)
	{}

void Keyboard_Reader::read_keys(int keycode, bool *exit, ALLEGRO_FONT *font)
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
		add_char(-32);
		break;
	default:
		add_char(keycode);
		std::cout << "final: " << this->length << std::endl;
		std::cout << this->buffer << std::endl;
		break;
	}

	draw_buffer(-500, -450, this->buffer, font);
}

void Keyboard_Reader::add_char(int letter)
{
	if (this->length == 99) {
		std::cout << "Buffer está cheio" << std::endl;
		return;
	}
	letter += 64;
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

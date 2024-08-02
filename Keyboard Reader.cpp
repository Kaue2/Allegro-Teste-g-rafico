#include "Keyboard Reader.h"
#include <string>
#include <iostream>


Keyboard_Reader::Keyboard_Reader() :
	buffer(),
	length(0)
	{}

void Keyboard_Reader::read_keys(int keycode, bool *exit)
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
	default:
		add_char(keycode);
		std::cout << "final: " << this->length << std::endl;
		std::cout << this->buffer << std::endl;
		break;
	}
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

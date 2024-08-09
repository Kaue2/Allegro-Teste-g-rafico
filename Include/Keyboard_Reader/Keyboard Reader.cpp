#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <string>
#include <iostream>
#include "Keyboard Reader.h"
#include "../Colors/Colors.h"

Keyboard_Reader::Keyboard_Reader()
{
	buffer = al_ustr_new("");
}

void Keyboard_Reader::read_keys(int keycode, bool *exit, ALLEGRO_FONT *font)
{
	switch (keycode)
	{
	case 27: // esc 
		*exit = true;
		break;
	case 8: //backspace
		remove_char();
		std::cout << "Quantidade de elementos: " << this->buffer->slen << std::endl;
		//std::cout << this->buffer << std::endl;
		break;
	case 13:
		break;
	default:
		add_char(keycode);
		std::cout << "final: " << this->buffer->slen << std::endl;
		//std::cout << this->buffer << std::endl;
		break;
	}
	clear_screen_buffer();
	draw_buffer(-500, -450, this->buffer, font);
}

void Keyboard_Reader::add_char(int letter)
{
	al_ustr_append_chr(buffer, letter);
	printf("%d\n", buffer->slen);
	printf("%s\n", al_cstr(buffer));
}

void Keyboard_Reader::remove_char()
{
	al_ustr_remove_chr(buffer, buffer->slen -1);
}

void Keyboard_Reader::draw_buffer(int pos_x, int pos_y, ALLEGRO_USTR* message, ALLEGRO_FONT *font)
{
	//al_draw_text(font, al_map_rgb(255,255,255), pos_x, pos_y, NULL, message);
	al_draw_ustr(font, white, pos_x, pos_y, NULL, message);
	//al_draw_filled_rectangle(-510, -423, 20 * 15 - 500, -396, colors.green);
}

void Keyboard_Reader::clear_screen_buffer()
{
	al_draw_filled_rectangle(-510, -450, 20 * 15 - 500, -423, gray);
}

#include<allegro5/allegro.h>
#pragma once

class Keyboard_Reader
{
public:
	char buffer[100];

	Keyboard_Reader();
	void read_keys(int keycode, bool *exit);
	void add_char(int letter);
	void remove_char();

	int get_final() const;

private:
	int length;
};

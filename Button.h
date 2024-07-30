#include<allegro5/allegro.h>
#pragma once

class Button {
public:
	int x;
	int y;
	int width;
	int heigth;
	int screen_num;
	ALLEGRO_COLOR color;


	Button(int x, int y, int width, int height, ALLEGRO_COLOR color, int screen_num);

	void draw_rect();

	int* action(int* display_game);
};
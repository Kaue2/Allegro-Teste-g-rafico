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

	virtual void action(int* display_game, bool *redraw);
	virtual void click_event(int mouse_x, int mouse_y, int *display_game, bool *redraw);
};
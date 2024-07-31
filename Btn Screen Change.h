#include "Button.h"
#pragma once
class Btn_Screen_Change : virtual public Button
{
public:
	int go_to_screen;

	Btn_Screen_Change(int x, int y, int width, int height, ALLEGRO_COLOR color, int screen_num, int go_to_screen);

	void action(int* display_game, bool redraw) override;
	void click_event(int mouse_x, int mouse_y, int* display_game, bool redraw) override;
};

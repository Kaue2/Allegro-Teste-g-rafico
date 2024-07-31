#include "Btn Screen Change.h"

Btn_Screen_Change::Btn_Screen_Change(int x, int y, int width, int height, ALLEGRO_COLOR color, int screen_num, int go_to_screen) : 
	Button(x, y, width,  height, color,  screen_num),
	go_to_screen(go_to_screen){}


void Btn_Screen_Change::click_event(int mouse_x, int mouse_y, int* display_game, bool redraw) {
	if (mouse_x >= this->x && mouse_x <= this->x + this->width &&
		mouse_y >= this->y && mouse_y <= this->y + this->heigth && 
		this) {
		action(display_game, redraw);
	}
}



void Btn_Screen_Change::action(int* display_game, bool redraw) {
	*display_game = this->go_to_screen;
}
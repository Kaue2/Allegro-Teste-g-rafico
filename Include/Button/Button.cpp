#include "Button.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

Button::Button(int x, int y, int width, int height, ALLEGRO_COLOR color, int screen_num) : 
	x(x), 
	y(y),
	width(width), 
	heigth(height),
	color(color),
	screen_num(screen_num){}

void Button::draw_rect(){
	al_draw_rectangle(x, y, x + width, y + heigth, color, 1);
}

// usar interface para implementação?
void Button::action(int* display_game, bool *redraw) {

}

void Button::click_event(int mouse_x, int mouse_y, int* display_game, bool *redraw) {

}
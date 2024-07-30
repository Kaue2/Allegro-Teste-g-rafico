#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include "Button.h"
#include "Button Colection.h"

ALLEGRO_COLOR white = al_map_rgb(255,255,255);
ALLEGRO_COLOR green = al_map_rgb(0, 200, 0);

Button btn_str =  Button(-100, -25, 200, 50, white, 0);
Button_Colection colection =  Button_Colection();

void draw_screens(int screen_num, ALLEGRO_FONT* font) {
	if (screen_num == 1) {
		btn_start(font);
		colection.add(btn_str);
	}
}

void btn_start(ALLEGRO_FONT* font) {
	//al_draw_rectangle(-100, -25, 100, 25, white, 1);
	btn_str.draw_rect();
	al_draw_text(font, white, -60, -17, 0, "Bem vindo");
}

void create_canvas(float width, float height) {
	al_draw_line(-width/2, 0, width/2, 0, white, 1); // eixo X
	al_draw_line(0, -height/2, 0, height/2, white, 1); // eixo y
}

void linear_function(float m, float b) {
	float y;
	// para o computador as coordenadas y são invertidas
	// para cima o y está decrescendo e quando vamos para baixo ele cresce
	for (int x = -500; x < 500; x++) {
		y = m * x + b;
		al_draw_pixel(x, -y, green); // invertemos o Y para agir como esperado
	}
}

void click_event(int screen_num, int mouse_pos_x, int mouse_pos_y) {
	for (int i = 0;  i < colection.length(); i++) {
		if (colection.btn_colection[i].screen_num == screen_num) {
			if (mouse_pos_x >= colection.btn_colection[i].x && 
				mouse_pos_x <= colection.btn_colection[i].x + colection.btn_colection[i].width &&
				mouse_pos_y >= colection.btn_colection[i].y &&
				mouse_pos_y <= colection.btn_colection[i].y + colection.btn_colection[i].heigth) {
				colection.btn_colection[i].
			}
		}
	}
}
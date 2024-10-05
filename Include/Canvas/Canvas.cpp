#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <iostream>
#include <vector>
#include "../Button/Btn Screen Change.h"
#include "../Button/Button Colection.h"
#include "../Colors/Colors.h"

Btn_Screen_Change btn_str = Btn_Screen_Change(-100, -25, 200, 50, white, 0, 1);
Button_Colection<Btn_Screen_Change> colection = Button_Colection<Btn_Screen_Change>();

void create_canvas(float width, float height) {
	al_draw_line(-width / 2, 0, width / 2, 0, white, 1); // eixo X
	al_draw_line(0, -height / 2, 0, height / 2, white, 1); // eixo y
}

void linear_function(float m, float b) {
	float y;
	// para o computador as coordenadas y são invertidas
	// para cima o y está decrescendo e quando vamos para baixo ele cresce
	for (float x = -500; x < 500; x+= 0.1) {
		y = m * x + b;
		al_draw_pixel(x * 10, -y * 10, green); // invertemos o Y para agir como esperado
	}
}

void draw_screens(int screen_num, ALLEGRO_FONT* font) {
	al_clear_to_color(black);
	if (screen_num == 0) {
		btn_str.draw_rect();
		al_draw_text(font, white, -60, -17, 0, "Bem vindo");
		colection.colection.push_back(btn_str);
	}
	if (screen_num == 1) {
		create_canvas(1000, 1000);
		al_draw_filled_rectangle(-510, -450, 20 * 15 - 500, -423, gray);
		//linear_function(8, 0);
	}
}

void btn_click_event(int *screen_num, int mouse_pos_x, int mouse_pos_y, bool *redraw) {
	for (size_t i = 0; i < colection.colection.size(); i++) {
		if (colection.colection[i].screen_num == *screen_num) {
			std::cout << "i: " << i << " screen number: " << *screen_num << " length: " << colection.colection.size() << std::endl;
			colection.colection[i].click_event(mouse_pos_x, mouse_pos_y, screen_num, redraw);
		}
	}
}


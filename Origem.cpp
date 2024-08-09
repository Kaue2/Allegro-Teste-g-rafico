#include <iostream>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/keyboard.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdbool.h>
#include <math.h>
#include "Include/Canvas/Canvas.h"
#include "Include/Keyboard_Reader/Keyboard Reader.h"

enum display_game {
	menu,
	main_screen
};

float heigth = 1000;
float width = 1000;
Keyboard_Reader Keyboard_reader;

void apply_transformation(float x, float y) {
	ALLEGRO_TRANSFORM transform;
	al_identity_transform(&transform);
	al_translate_transform(&transform, x, y);
	al_use_transform(&transform);
}

void draw_game(void) {
	al_flip_display();
}

int main(int argc, char** argv) {

	if (!al_init()) {
		std::cerr << "Erro ao iniciar allegro" << std::endl;
		return 1;
	}

	if (!al_install_keyboard()) {
		std::cerr << "Erro ao iniciar teclado" << std::endl;
		return 1;
	}

	if (!al_init_primitives_addon()) {
		std::cerr << "Erro ao iniciar primitivos" << std::endl;
		return 1;
	}

	if (!al_init_font_addon()) {
		std::cerr << "Erro ao iniciar fonte addon" << std::endl;
		return 1;
	}

	if (!al_init_ttf_addon()) {
		std::cerr << "Erro ao iniciar ttf" << std::endl;
	}

	if (!al_install_mouse()) {
		std::cerr << "Erro ao instalar o mouse" << std::endl;
	}

	ALLEGRO_FONT* font = al_load_font("font.ttf", 18, 0);
	if (!font) { 
		std::cerr << "Erro ao iniciar a fonte" << std::endl;
	}

	//get_window_size();
	ALLEGRO_DISPLAY* display = al_create_display(width, heigth);
	if (!display) {
		std::cerr << "Erro ao iniciar o display" << std::endl;
		return 1;
	}

	ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
	if (!timer) {
		std::cerr << "Erro ao inciar o timer" << std::endl;
		return 1;
	}

	ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
	if (!queue) {
		std::cerr << "Erro ao iniciar a fila de eventos" << std::endl;
		return 1;
	}
	

	apply_transformation(500,500);

	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_timer_event_source(timer));
	al_register_event_source(queue, al_get_mouse_event_source());

	bool exit = false;
	bool* exit_pointer = &exit;
	bool draw = false;
	int screen_state = menu;
	int* screen_pointer = &screen_state;
	bool redraw = false;
	bool* redraw_pointer = &redraw;
	ALLEGRO_EVENT event;
	al_start_timer(timer);
	int mouse_pos_x;
	int mouse_pos_y;
	

	//create_canvas(width, heigth);
	draw_screens(screen_state, font);

	while (!exit){
		al_wait_for_event(queue, &event);

		switch (event.type)
		{
		case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
			mouse_pos_x = event.mouse.x;
			mouse_pos_y = event.mouse.y;
			btn_click_event(screen_pointer, mouse_pos_x, mouse_pos_y, redraw_pointer);
			
			break;
		case ALLEGRO_EVENT_TIMER:
			//mouse_pos_x = event.mouse.x;
			//mouse_pos_y = event.mouse.y;
			//std::cout << "X:" << mouse_pos_x << " Y:" << mouse_pos_y <<std::endl;
			draw = true;
			break;
		case ALLEGRO_EVENT_KEY_CHAR:
			if (screen_state == 1) {
				std::cout << "unichar: " << event.keyboard.unichar << std::endl;
				Keyboard_reader.read_keys(event.keyboard.unichar, exit_pointer, font);
			}
			break;
		}

		if (draw) {
			draw_game();
			draw = false;
		}

		if (redraw) {
			draw_screens(screen_state, font);
			redraw = false;
		}
	}

	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_event_queue(queue);
	

	return 0;
}
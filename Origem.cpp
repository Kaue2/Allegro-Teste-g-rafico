#include <iostream>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/keyboard.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdbool.h>
#include <math.h>
#include "Canvas.h"
#include "DeviceDisplay.h"
#include "Button Colection.h"

enum display_game {
	menu,
	main_screen
};

float heigth = 1000;
float width = 1000;

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

	ALLEGRO_FONT* font = al_load_font("font.ttf", 24, 0);
	if (!font) { 
		std::cerr << "Erro ao iniciar a fonte" << std::endl;
	}

	//get_window_size();
	ALLEGRO_DISPLAY* display = al_create_display(width, heigth);
	if (!display) {
		std::cerr << "Erro ao iniciar o display" << std::endl;
		return 1;
	}

	ALLEGRO_TIMER* timer = al_create_timer(5.0);
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
	bool draw = false;
	ALLEGRO_EVENT event;
	al_start_timer(timer);
	int mouse_pos_x;
	int mouse_pos_y;
	int screen_state = menu;
	int* screen_pointer = &screen_state;
	bool redraw = false;

	//create_canvas(width, heigth);
	draw_screens(screen_state, font);

	while (!exit){
		al_wait_for_event(queue, &event);

		switch (event.type)
		{
		case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
			mouse_pos_x = event.mouse.x;
			mouse_pos_y = event.mouse.y;
			btn_click_event(screen_pointer, mouse_pos_x, mouse_pos_y, redraw);
			break;
		case ALLEGRO_EVENT_TIMER:
			draw = true;
			break;
		case ALLEGRO_EVENT_KEY_DOWN:
			if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
				exit = true;
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
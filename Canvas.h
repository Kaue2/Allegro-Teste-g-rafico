#pragma once

void create_canvas(float width, float height);
void linear_function(float m, float a);
void draw_screens(int screen_num, ALLEGRO_FONT* font);
void btn_click_event(int* screen_num, int mouse_pos_x, int mouse_pos_y, bool *redraw);

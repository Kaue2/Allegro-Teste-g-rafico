#include "Colors.h"

Colors::Colors() {
	white = al_map_rgb(255, 255, 255);
	black = al_map_rgb(0, 0, 0);
	red = al_map_rgb(250, 0, 0);
	green = al_map_rgb(0, 250, 0);
	blue = al_map_rgb(0, 0, 250);
}
	

Colors::~Colors()
{

}


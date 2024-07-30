#include "Button.h"
#pragma once

class Button_Colection {
public:
	Button* btn_colection;

	Button_Colection();

	int add(Button btn);
	int remove(Button btn);
	int length();

private:
	int final;
};
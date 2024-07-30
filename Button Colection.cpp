#include <iostream>
#include "Button Colection.h"

Button_Colection::Button_Colection() :
	btn_colection((Button*)malloc(5 * sizeof(Button))),
	final(0) {}

/// <summary>
/// 
/// </summary>
/// <param name="btn">Espera uma instância de Button</param>
/// <returns>Posição do botão adcionado</returns>
int Button_Colection::add(Button btn) {
	if (this->final == 5) {
		std::cerr << "A coleção está cheia" << std::endl;
		return -1;
	}
	this->btn_colection[final++] = btn;
	return this->final - 1;
}

/// <summary>
/// 
/// </summary>
/// <param name="btn">Espera uma instância de Button</param>
/// <returns>Posição do Botão removido</returns>
int Button_Colection::remove(Button btn) {
	if (this->final == 0) {
		std::cerr << "A coleção está vazia" << std::endl;
		return -1;
	}
	this->final--;
	return this->final + 1;
}

int Button_Colection::length() {
	return this->final;
}
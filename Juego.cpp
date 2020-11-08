#include "Juego.h"


Juego::Juego() {
	ce = new int;
	*ce = 0;
}

void Juego::Init(Bitmap^ bmp, Graphics^ g) {
}

void Juego::Run(Bitmap^ bmp, Graphics^ g) {}

bool Juego::Colision(ArregloObstaculos* obj1, ArregloObstaculos* obj2) {
	return true;
}

void Juego::Mostrar_Mensaje_Final(Graphics^ g) {}

bool Juego::Fin_del_Juego() {
	return true;
}

Juego::~Juego(){}
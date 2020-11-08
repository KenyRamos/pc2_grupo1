#pragma once
#include "Entidad.h"

class Monigote : public Entidad
{
public:
	Monigote();
	Monigote(int px, int py, Bitmap^ bmp);
	void Dibujar(Graphics^ g, Bitmap^ bmp);
	void Mover_Monigote(Graphics^ g);
	int retornar_ancho() { return w; }
	int retornar_alto() { return h; }
};
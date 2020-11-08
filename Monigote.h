#pragma once
#include "Entidad.h"

class Monigote : public Entidad
{
public:
	Monigote();
	Monigote(int px, int py, Bitmap^ bmp);z
	void Dibujar(Graphics^ g, Bitmap^ bmp);
	int retornar_ancho() { return w; }
	int retornar_alto() { return h; }
};
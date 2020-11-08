#pragma once
#include "Entidad.h"

class Monigote : public Entidad
{
private:
	int w, h, f, c;

public:
	Monigote();
	Monigote(int px, int py, Bitmap^ bmp);
	void Dibujar(Graphics^ g, Bitmap^ bmp);
	int retornar_ancho() { return w; }
	int retornar_alto() { return h; }
};


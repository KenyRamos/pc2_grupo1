#pragma once
#include "Entidad.h"
enum SpriteMonigote
{
	CaminarArriba,
	CaminarIzquierda,
	CaminarAbajo,
	CaminarDerecha,

	Morir
};

class Monigote : public Entidad
{
private:
	
	SpriteMonigote accion;

public:
	Monigote(Bitmap^ img);
	Monigote(int px, int py, Bitmap^ bmp);
	void Dibujar(Graphics^ g, Bitmap^ bmp);
	int retornar_ancho() { return w; }
	int retornar_alto() { return h; }
};


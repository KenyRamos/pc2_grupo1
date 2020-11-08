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
	int f, c;
	
	SpriteMonigote accion;

public:
	Monigote();
	Monigote(int px, int py, Bitmap^ bmp);
	void SetAccion(SpriteMonigote value);
	void Mostrar(Graphics^ g, Bitmap^ bmp);
	void Mover(Graphics^ g);

	
};


	



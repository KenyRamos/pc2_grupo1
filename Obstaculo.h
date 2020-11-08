#pragma once
#include "Dependencias.h"
#include "Entidad.h"

class Obstaculo : public Entidad
{
public:
	Obstaculo(Bitmap^ img) : Entidad()
	{
		x = 0;
		y = 0;

		ancho = img->Width;
		alto = img->Height;
	}
	void Mostrar(Graphics^ g, Bitmap^ img)
	{
		g->DrawImage(img, Area());
	}

};


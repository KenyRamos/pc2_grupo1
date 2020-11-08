#pragma once
#include "Dependencias.h"
#include "Entidad.h"

class Obstaculo : public Entidad
{
public:
	Obstaculo() : Entidad()
	{
		x = 0;
		y = 0;
	}
	void Mostrar(Graphics^ g, Bitmap^ img)
	{
		int ancho = img->Width;
		int alto = img->Height;
		g->DrawImage(img, Area());
	}

};


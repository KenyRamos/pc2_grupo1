#pragma once
#include "Dependencias.h"
#include "Entidad.h"

enum SpriteMoneda
{
	ORO,
	PLATA,
	COBRE
};

class Moneda : public Entidad
{
private:
	SpriteMoneda tipo_moneda;

public:
	Moneda(int px, int py, Bitmap^ bmp);
	void Mostrar(Graphics^ g, Bitmap^ bmp);
	void setTipoMoneda(SpriteMoneda tipo_moneda);
	~Moneda();



};


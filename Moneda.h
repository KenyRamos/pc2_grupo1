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
	int tipo;
	SpriteMoneda tipo_moneda;

public:
	Moneda();
	~Moneda();
	void Mostrar(Graphics^ g, Bitmap^ bmp);
	void Mover(int anchoPanel, int altoPanel, int direccion);
	void setTipoMoneda(SpriteMoneda tipo_moneda);
};


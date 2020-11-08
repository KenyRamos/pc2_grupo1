#include "Moneda.h"

Moneda::Moneda(int px, int py, Bitmap^ bmp) : Entidad()
{
	ancho = bmp->Width / 10;
	alto = bmp->Height / 3;
	dx = dy = 0;
}

void Moneda::Mostrar(Graphics^ g, Bitmap^ bmp)
{
	Rectangle porcion = Rectangle(IDx * ancho, tipo_moneda * alto, ancho, alto);
	g->DrawImage(bmp, Area(), porcion, GraphicsUnit::Pixel);

	if (dx != 0 || dy != 0)
	{
		if (tipo_moneda >= ORO && tipo_moneda <= COBRE)
			IDx = (IDx + 1) % 10;
	}
}

void  Moneda::setTipoMoneda(SpriteMoneda tipo_moneda) {
	this->tipo_moneda = tipo_moneda;
}
#include "Moneda.h"

Moneda::Moneda() : Entidad()
{
	dx = dy = 0;
}

Moneda::~Moneda()
{
}

void Moneda::Mostrar(Graphics^ g, Bitmap^ bmp)
{
	int ancho = bmp->Width / 10;
	int alto = bmp->Height / 3;
	Rectangle porcion = Rectangle(IDx * ancho, tipo_moneda * alto, ancho, alto);
	g->DrawImage(bmp, Area(), porcion, GraphicsUnit::Pixel);

	if (dx != 0 || dy != 0)
	{
		if (tipo_moneda >= ORO && tipo_moneda <= COBRE)
			IDx = (IDx + 1) % 10;
	}
}

void Moneda::Mover(int anchoPanel, int altoPanel, int direccion) {
	switch (tipo) {
	case 1:
		dx = -6;
		break;
	case 2:
		dx = -4;
		break;
	};

	switch (direccion) {
	case 0: //derecha
		IDy = 0;
		break;
	case 1: //izquierda
		IDy = 0;
		break;
	};

	/*Definir mis limites de mi panel donde me voy a mover y evitar que mi objeto se salga de los limites del panel*/
	if (x + dx <= 0 || x + dx + ancho >= anchoPanel)
		dx = dx * -1;

	/*Aumentar el deltaX*/
	x += dx;

	IDx += 1;

	if (IDx == 10)
		IDx = 0;
}

void  Moneda::setTipoMoneda(SpriteMoneda tipo_moneda) {
	this->tipo_moneda = tipo_moneda;
}
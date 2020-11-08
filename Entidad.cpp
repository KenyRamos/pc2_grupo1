#include "Entidad.h"

Entidad::Entidad() {
	x = y = 0;
	dx = dy = 0;
	ancho = alto = 0;
}
Entidad::~Entidad() {

}
int Entidad::GetX()
{
	return x;
}
int Entidad::GetY()
{
	return y;
}
int Entidad::GetDX()
{
	return dx;
}
int Entidad::GetDY()
{
	return dy;
}
int Entidad::GetAncho()
{
	return ancho;
}
int Entidad::GetAlto()
{
	return alto;
}
int Entidad::GetIDx()
{
	return IDx;
}

void Entidad::SetX(int value)
{
	x = value;
}
void Entidad::SetY(int value)
{
	y = value;
}
void Entidad::SetDX(int value)
{
	dx = value;
}
void Entidad::SetDY(int value)
{
	dy = value;
}
void Entidad::SetAncho(int value)
{
	ancho = value;
}
void Entidad::SetAlto(int value)
{
	alto = value;
}
void Entidad::Mover(Graphics^ g)
{
	x += dx;
	y += dy;
}
void Entidad::Mostrar(Graphics^ g, Bitmap^ img)
{
	g->FillRectangle(Brushes::Black, x, y, ancho, alto);
}
Rectangle Entidad::Area()
{
	return Rectangle(x, y, ancho, alto);
}


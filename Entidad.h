#pragma once
#include <Dependencias.h>

class Entidad
{
protected:
	int x, y;
	int dx, dy;
	int ancho, alto;
	int IDx;
public:
	Entidad() {
		x = y = 0;
		dx = dy = 0;
		ancho = alto = 0;
	}
	int GetX()
	{
		return x;
	}
	int GetY()
	{
		return y;
	}
	int GetDX()
	{
		return dx;
	}
	int GetDY()
	{
		return dy;
	}
	int GetAncho()
	{
		return ancho;
	}
	int GetAlto()
	{
		return alto;
	}
	int GetIDx()
	{
		return IDx;
	}

	void SetX(int value)
	{
		x = value;
	}
	void SetY(int value)
	{
		y = value;
	}
	void SetDX(int value)
	{
		dx = value;
	}
	void SetDY(int value)
	{
		dy = value;
	}
	void SetAncho(int value)
	{
		ancho = value;
	}
	void SetAlto(int value)
	{
		alto = value;
	}
	virtual void Mover(Graphics^ g)
	{
		x += dx;
		y += dy;
	}
	virtual void Mostrar(Graphics^ g, Bitmap^ img)
	{
		g->FillRectangle(Brushes::Black, x, y, ancho, alto);
	}
};


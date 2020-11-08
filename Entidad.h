#pragma once
#include "Dependencias.h"

class Entidad
{
protected:
	int x, y;
	int dx, dy;
	int ancho, alto;
	int IDx;
	int w, h, f, c;
public:
	Entidad();
	int GetX();
	int GetY();
	int GetDX();
	int GetDY();
	int GetAncho();
	int GetAlto();
	int GetIDx();
	void SetX(int value);
	void SetY(int value);
	void SetDX(int value);
	void SetDY(int value);
	void SetAncho(int value);
	void SetAlto(int value);
	virtual void Mover(Graphics^ g);
	virtual void Mostrar(Graphics^ g, Bitmap^ img);
	Rectangle Area();
};


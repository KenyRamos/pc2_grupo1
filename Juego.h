#pragma once
#include "Dependencias.h"
#include "Monigote.h"
#include "ArregloObstaculos.h"


class Juego
{
private:
	Monigote* monigote;
	ArregloObstaculos** arrayObst;
	int* ce;

public:
	Juego();
	void Init(Bitmap^ bmp, Graphics^ g);
	void Run(Bitmap^ bmp, Graphics^ g);
	bool Colision(ArregloObstaculos* obj1, ArregloObstaculos* obj2);
	bool Fin_del_Juego();
	void Mostrar_Mensaje_Final(Graphics^ g);
	~Juego();


};


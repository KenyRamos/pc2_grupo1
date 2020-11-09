#pragma once
#include "Moneda.h"
class ArregloMonedas
{
private:
	int ne; //Definir Nro. de Elementos del arreglo
	Moneda** arrMoneda; //Definir el arreglo según la clase especificado.
	int nAux;
public:
	ArregloMonedas();
	~ArregloMonedas();
	void Muestrate(System::Drawing::Graphics^ C, System::Drawing::Bitmap^ B);
	void Muevete(int anchoPanel, int altoPanel, int direccion);
	void Agregar(int rTipoEnemigo, int yJugador);
	/*void Eliminar();
	void Colision(int xObjeto, int yObjeto, int anchoObjeto, int altoObjeto);*/
	int Get_ne();
	int Get_nAux();
};

#include "ArregloMonedas.h"

ArregloMonedas::ArregloMonedas() {
	this->ne = 0;
	this->arrMoneda = NULL;
	this->nAux = 0;
}
ArregloMonedas::~ArregloMonedas() {
	/*Evitar Errores y salir del método*/
	if (ne == 0 || arrMoneda == NULL)
		return;

	for (int i = 0; i < ne; i++) //Recorrer tus objetos del arreglo
		delete arrMoneda[i];//Un elemento de tu arreglo
}
void ArregloMonedas::Muestrate(System::Drawing::Graphics^ C, System::Drawing::Bitmap^ B) {
	/*Evitar Errores y salir del método*/
	if (ne == 0 || arrMoneda == NULL)
		return;

	for (int i = 0; i < ne; i++) //Recorrer tus objetos del arreglo
	{
		//if (arrEnemigo[i]->Get_estadoMuerto() == false)
		arrMoneda[i]->Mostrar(C, B);//Mostrar el objeto
	}
}
void ArregloMonedas::Muevete(int anchoPanel, int altoPanel, int direccion) {
	/*Evitar Errores y salir del método*/
	if (ne == 0 || arrMoneda == NULL)
		return;

	for (int i = 0; i < ne; i++) //Recorrer tus objetos del arreglo
		arrMoneda[i]->Mover(anchoPanel, altoPanel, direccion);//Mostrar el objeto
}
void ArregloMonedas::Agregar(int rTipoEnemigo, int yJugador) {
	//1. Creamos nuestro arreglo auxiliar con n + 1 elementos
	Moneda** arrAuxMoneda;
	arrAuxMoneda = new Moneda * [ne + 1]; //Defines el nro de Elementos que tendrá tu arreglo auxiliar
	//2. Verificar si es que el arreglo original tiene data
	if (arrMoneda != NULL) {
		//Si si tiene data el arreglo original
		for (int i = 0; i < ne; i++)
			arrAuxMoneda[i] = arrMoneda[i];
	}
	int y;
	int dx;
	int x = 300;

	int dy = 0;
	int ancho = 35;
	int alto = 35;
	int indiceFX = 0;
	int indiceFY = 0;
	int anchoF = 4;
	int altoF = 1;
	int tipo = rTipoEnemigo;
	int vida = 0;
	bool estadoMuerto = false;
	Moneda* m1 = new Moneda();
	m1->SetX(x);
	m1->SetY(y);
	m1->SetAncho(ancho);
	m1->SetAlto(alto);

	//4. Asignamos el nuevo enemigo en nuestro último slot de nuestro arreglo
	arrAuxMoneda[ne] = m1;
	//5. Pasar lo de tu arreglo auxiliar a tu arreglo original
	arrMoneda = arrAuxMoneda;
	//6. Sumamos el nro de elementos a uno más
	ne += 1;
}
//
//
//void ArregloMonedas::Eliminar() {
//	nAux = 0;
//	int indiceAux = 0;
//	//1. Identificar la cantidad de eliminados
//	if (arrEnemigo != NULL) {
//		//Si si tiene data el arreglo original
//		for (int i = 0; i < ne; i++)
//			if (arrEnemigo[i]->Get_estadoMuerto())
//				nAux += 1;;
//	}
//	//2. Creamos nuestro arreglo auxiliar con n - nAux (Balas Muertas)
//	CEnemigo** arrAuxEnemigo;
//	arrAuxEnemigo = new CEnemigo * [ne - nAux]; //Defines el nro de Elementos que tendrá tu arreglo auxiliar
//	//3. Verificar si es que el arreglo original tiene data
//	if (arrEnemigo != NULL) {
//		//Si si tiene data pasamos a nuestro nuevo arreglo
//		for (int i = 0; i < ne; i++) {
//			if (arrEnemigo[i]->Get_estadoMuerto() == false) {
//				arrAuxEnemigo[indiceAux] = arrEnemigo[i];
//				indiceAux++;
//			}
//		}
//	}
//	//3.1 Eliminamos todo lo de nuestro arreglo original
//	delete[] arrEnemigo;
//	//4. Pasar lo de tu arreglo auxiliar a tu arreglo original
//	arrEnemigo = arrAuxEnemigo;
//	//5. Definimos el nuevo n que tenemos
//	ne = ne - nAux;
//}
//
//void ArregloMonedas::Colision(int xObjeto, int yObjeto, int anchoObjeto, int altoObjeto) {
//	for (int i = 0; i < ne; i++) //Recorrer tus objetos del arreglo
//		arrEnemigo[i]->DetectarColision(xObjeto, yObjeto, anchoObjeto, altoObjeto);
//}

int ArregloMonedas::Get_ne() {
	return ne;
}
int ArregloMonedas::Get_nAux() {
	return nAux;
}
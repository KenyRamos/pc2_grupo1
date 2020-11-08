#include "Monigote.h"
Monigote::Monigote()
{
	x = 100;
	y = 100;
	ancho = alto = 50;
	dx = 1;
	dy = 1;
	IDx = 0;
	IDy = 0;
	f = c = 0;
}
Monigote::Monigote(int px, int py, Bitmap^ bmp): Entidad()
{
	ancho = alto = 50;

	f = c = 0;
}
void Monigote::Mostrar (Graphics^ g, Bitmap^ bmp)
{
	int ancho = bmp->Width / 9;
	int alto = bmp->Height / 4;
	Rectangle porcion = Rectangle(IDx  * ancho, IDy * alto, ancho, alto);
	g->DrawImage(bmp, Area(), porcion, GraphicsUnit::Pixel);

	if (dx != 0 || dy != 0){
		//if (accion >= CaminarArriba && accion <= CaminarAbajo)
			IDx = (IDx + 1) % 9;
	}
}

void Monigote::SetAccion(SpriteMonigote value){
	accion = value;
}

void Monigote::Mover(Graphics^ g){

	//if (x - dx < 0 || x + ancho + dx > g->VisibleClipBounds.Width)
	//dx = dx *-1;
	//if (y - dy < 0 || y + alto + dy > g->VisibleClipBounds.Height)
	//dy = dy * -1;

	switch (accion) {
		case SpriteMonigote::CaminarArriba:
			IDy = 0;
			y -= dy;
			break;
		case SpriteMonigote::CaminarAbajo:
			IDy = 2;
			y += dy;
			break;
		case SpriteMonigote::CaminarDerecha:
			IDy = 3;
			x += dx;
			break;
		case SpriteMonigote::CaminarIzquierda:
			IDy = 1;
			x -= dx;
			break;
	};
	//f++;

	//if (f == 7)
		//f = 0;

}




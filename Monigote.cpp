#include "Monigote.h"
Monigote::Monigote()
{
	ancho = alto = 50;
	dx = 1;

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
	Rectangle porcion = Rectangle(c * ancho, f * alto, ancho, alto);
	g->DrawImage(bmp, Area(), porcion, GraphicsUnit::Pixel);
}

void SetAccion(SpriteMonigote value){
	
}

void Monigote::Mover(Graphics^ g){
	if (x + dx >= 0 && x + ancho + dx < g->VisibleClipBounds.Width)
		x += dx;
	if (y + dy >= 0 && y + alto + dy < g->VisibleClipBounds.Height)
		y += dy;

	x += dx;
	f++;

	if (f == 7)
		f = 0;

}




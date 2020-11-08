#include "Monigote.h"
Monigote::Monigote(Bitmap^ bmp)
{

}
Monigote::Monigote(int px, int py, Bitmap^ bmp): Entidad()
{
	ancho = bmp->Width / 9;
	alto = bmp->Height / 4;
	f = c = 0;
}
void Monigote::Mostrar (Graphics^ g, Bitmap^ bmp)
{
	Rectangle porcion = Rectangle(c * ancho, f * alto, ancho, alto);
	g->DrawImage(bmp, Area(), porcion, GraphicsUnit::Pixel);
}

void SetAccion(SpriteMonigote value){
	accion = value;
	
}

void Mover(Graphics^ g){
	if (x + dx >= 0 && x + ancho + dx < g->VisibleClipBounds.Width)
		x += dx;
	if (y + dy >= 0 && y + alto + dy < g->VisibleClipBounds.Height)
		y += dy;
	
}




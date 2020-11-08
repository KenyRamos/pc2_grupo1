#include "Monigote.h"
Monigote::Monigote()
{

}
Monigote::Monigote(int px, int py, Bitmap^ bmp): Entidad()
{
	w = bmp->Width / 3;
	h = bmp->Height / 4;
	f = c = 0;
}
void Monigote::Dibujar(Graphics^ g, Bitmap^ bmp)
{
	Rectangle porcion = Rectangle(c * w, f * h, w, h);
	g->DrawImage(bmp, Area(), porcion, GraphicsUnit::Pixel);
}

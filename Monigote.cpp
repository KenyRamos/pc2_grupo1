#include "Monigote.h"
Monigote::Monigote()
{

}
Monigote::Monigote(int px, int py, Bitmap^ bmp): Entidad()
{
	w = bmp->Width / 9;
	h = bmp->Height / 4;
	f = c = 0;
}
void Monigote::Dibujar(Graphics^ g, Bitmap^ bmp)
{
	Rectangle porcion = Rectangle(c * w, f * h, w, h);
	g->DrawImage(bmp, Area(), porcion, GraphicsUnit::Pixel);
}
void Monigote::Mover_Monigote(Graphics^ g)
{
	if (x + dx >= 0 && x + ancho + dx < g->VisibleClipBounds.Width)
		x += dx;
	if (y + dy >= 0 && y + alto + dy < g->VisibleClipBounds.Height)
		y += dy;
}
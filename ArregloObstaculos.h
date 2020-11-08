#pragma once
#include "Obstaculo.h"
class ArregloObstaculos : public Obstaculo
{
private:
	vector<Obstaculo*> arr;

public:
	ArregloObstaculos(int n, Rectangle obj, Bitmap^ img){
		for (int i = 0; i < n; i++)
		{
			Obstaculo* obs = new Obstaculo();
			if (obs->Area().IntersectsWith(obj) == false && Colision(obs->Area()) == false)
				arr.push_back(obs);
			else
			{
				delete obs;
				i--;
			}
		}
	}
	~ArregloObstaculos()
	{
		for (int i = 0; i < arr.size(); i++)
			delete arr.at(i);
	}

	bool Colision(Rectangle obj)
	{
		for each (Obstaculo * obs in arr)
		{
			if (obs-> NextArea().IntersectsWith(obj))
				return true;
		}
		return false;
	}

	void Mover(Graphics^ g)
	{
		for each (Obstaculo * obs in arr)
		{
			obs->Mover(g);
		}
	}
	void Mostrar(Graphics^ g, Bitmap^ img)
	{
		for (Obstaculo* obs : arr)
		{
			obs->Mostrar(g, img);
		}
	}

};


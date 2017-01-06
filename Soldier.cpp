#include "Soldier.h"

//*Constructor*//
Soldier::Soldier(int x, int y)
{
	speed = 2;
	GameObject::initiate(x, y, speed, 20, 20);
	setID(ENEMY);
}

//*Overide update pure virtual function*//
void Soldier::update()
{
	y += speed;
	if(y < 0 )
		setAlive(false);
}

//*Overide render pure virtual function*//
void Soldier::render()
{
	al_draw_filled_circle(x, y, 8, al_map_rgb(0, 50, 0));
}

//*Overide collided pure virtual function*//
void Soldier::collided(int otherObjectID)
{
	if(otherObjectID != ENEMY)
		setAlive(false);
}

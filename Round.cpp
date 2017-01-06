#include "Round.h"

//*Constructor*//
Round::Round(int x, int y)
{
	speed = 7;
	GameObject::initiate(x, y, speed, 0, 0);
	setID(ROUND);
}

//*Overide update pure virtual function*//
void Round::update()
{
	y -= speed;
	if(y < 0)
	   setAlive(false);
}

//*Overide render pure virtual function*//
void Round::render()
{
	al_draw_filled_circle(x, y, 3, al_map_rgb(180, 0, 0));
}

//*Overide collided pure virtual function*//
void Round::collided(int otherObjectID)
{
	if(otherObjectID == ENEMY)
		setAlive(false);
}

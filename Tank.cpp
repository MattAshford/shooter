#include "Tank.h"

//*Constructor*//
Tank::Tank(){}

//*Initiate*//
void Tank::initiate()
{
	speed = 5;
	GameObject::initiate((SCREEN_WIDTH / 2), (SCREEN_HEIGHT - 40), speed, 10, 12);

	setID(PLAYER);
	setAlive(true);
}

//*Overide update pure virtual function*//
void Tank::update()
{
	if(x < 0)
		x = 0;
	else if(x > SCREEN_WIDTH)
		x = SCREEN_WIDTH;

	if(y < 0)
		y = 0;
	else if(y > SCREEN_HEIGHT)
		y = SCREEN_HEIGHT;
}

//*Overide render pure virtual function*//
void Tank::render()
{
	al_draw_filled_rectangle(x + 3, y - 50, x - 3, y + 15, al_map_rgb(0, 108, 0));
	al_draw_filled_rectangle(x + 25, y +25, x - 25, y -25, al_map_rgb(0, 108, 0));
}
//*Move Tank*//
void Tank::moveUp()
{
	y -= speed;
}
void Tank::moveDown()
{
	y += speed;
}
void Tank::moveLeft()
{
	x -= speed;
}
void Tank::moveRight()
{
	x += speed;
}

//*Overide collided pure virtual function*//
void Tank::collided(int otherObjectID) {}


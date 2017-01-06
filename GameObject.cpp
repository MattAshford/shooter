#include "GameObject.h"

//*Game Object Constructor*//
GameObject::GameObject()
{
	x = 0;
	y = 0;	
	speed = 0;
	boundX = 0;
	boundY = 0;
	isAlive = true;
	isCollidable = true;
}

//*Initiate*//
void GameObject::initiate(int x, int y,int speed, int boundX, int boundY)
{
	GameObject::x = x;
	GameObject::y = y;
	GameObject::speed = speed;	
	GameObject::boundX = boundX;
	GameObject::boundY = boundY;
}

//*Check for collision*//
bool GameObject::checkCollisions(GameObject *otherObject)
{
	float otherObjectX = otherObject->getX();
	float otherObjectY = otherObject->getY();

	int otherObjectBoundX = otherObject->getBoundX();
	int otherObjectBoundY = otherObject->getBoundY();

	if( x + boundX > otherObjectX - otherObjectBoundX &&
		x - boundX < otherObjectX + otherObjectBoundX &&
		y + boundY > otherObjectY - otherObjectBoundY &&
		y - boundY < otherObjectY + otherObjectBoundY)
		return true;
	else
		return false;
}

//*tests if object is collidable*//
bool GameObject::collidable()
{
	return isAlive && isCollidable;
}

#pragma once

#include <iostream>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include "Globals.h"
//*Description of class*//
class GameObject
{
private:
	int ID;
	bool isAlive;
	bool isCollidable;

protected:
	int x;
	int y;	
	int speed;
	int boundX;
	int boundY;

public:
	GameObject();

	void initiate(int x, int y, int speed, int boundX, int boundY);
	void virtual update() = 0;
	void virtual render()= 0;

	int getX() {return x;}
	int getY() {return y;}

	void setX(int x) {GameObject::x = x;}
	void setY(int y) {GameObject::y = y;}

	int getBoundX() {return boundX;}
	int getBoundY() {return boundY;}

	int getID() {return ID;}
	void setID(int ID) {GameObject::ID = ID;}

	bool getAlive() {return isAlive;}
	void setAlive(bool isAlive) {GameObject::isAlive =isAlive;}

	bool checkCollisions(GameObject *otherObject);
	void virtual collided(int otherObjectID) = 0;
	bool collidable();
};

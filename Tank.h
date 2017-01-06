#pragma once

#include "GameObject.h"

//*Class description*//
class Tank : public GameObject
{
public:
	Tank();
	void initiate();
	void virtual update();
	void virtual render();
	void collided(int otherObjectID);

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
};

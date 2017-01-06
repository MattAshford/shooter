#pragma once

#include "GameObject.h"

//*class description*//
class Soldier : public GameObject
{
	public:
		Soldier(int x, int y);
		void virtual update();
		void virtual render();
		void virtual collided(int otherObjectID); 
};

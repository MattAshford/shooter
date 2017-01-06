#pragma once

#include "GameObject.h"

//*Class description*//
class Round : public GameObject
{
	public:
		Round(int x, int y);
		void virtual update();
		void virtual render();
		void virtual collided(int otherObjectID);
};

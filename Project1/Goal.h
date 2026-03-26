#pragma once
#include "GameObject.h"
#include <sgg/graphics.h>
#include "box.h"

class Goal : public GameObject, public Box
{
	bool side = true;
	float m_draw_height;

public:
	Goal(bool side);
	void update(float dt);
	void init();
	void draw();

};
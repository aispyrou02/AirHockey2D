#pragma once
#include "GameObject.h"
#include "box.h"
#include <sgg/graphics.h>
#include "GameState.h"


class Ball : public GameObject, public Box {


	bool side = true;
	float real_size;
	float v;
	float v2;
	float vv;
	float max_vel = 0.011f;
	float min_vel = -0.011f;

	
public:
	float velocity_x = 0.0f;
	float velocity_y = 0.0f;
	Ball(bool side);
	void update(float dt);
	void init();
	void draw();
	void start();
	void setSide(bool a) { side = a; }
};
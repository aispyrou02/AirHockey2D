#pragma once
#include "GameObject.h"
#include "box.h"
#include <sgg/graphics.h>
#include "GameState.h"
#include "box.h"


class Player : public GameObject  , public Box
{
	const float velocity = 6.0f;
	bool side = true;
	float real_size;


	float big = 0;
	float small = 0;
	

public:
	Player(bool side,const std::string& name="");


	void update(float dt);
	void init();
	void draw();
	void start();
	void collision(bool a);

	Box top_left;
	Box top_right;
	Box bottom_left;
	Box bottom_right;
	Box top;
	Box left;
	Box bottom;
	Box right;

	
};

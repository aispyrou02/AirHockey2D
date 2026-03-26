#pragma once
#include "string";
#include <sgg/graphics.h>
#include "GameObject.h"
#include "Player.h"
#include <list>
#include <iostream>
#include <vector>
#include <memory>

class Level : public GameObject
{
	float m_center_x = 8.0f;
	float m_center_y = 5.0f;

	bool point = false;

	graphics::Brush m_writing_brush;
	graphics::Brush m_writing_brush2;

	graphics::Brush m_winning_brush;

	std::vector<GameObject*> m_gameObjects;		


public:

	Level(const std::string& name = "level_0");
	void update(float dt);
	void init();
	void draw();
	void check_goal();
	void made_goal(bool side);
	~Level();



};

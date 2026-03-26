#pragma once
#include "Goal.h"
#include "Player.h"
#include "sgg/graphics.h"
#include "GameObject.h"
#include "string"
#include "GameState.h"
#include "util.h"

Goal::Goal(bool side)
	:side(side)
{
	m_draw_height = 3.0;
	m_height = m_draw_height*1.9f/3.0f;
	m_width = 0.2f;

}

void Goal::update(float dt)
{
}

void Goal::init()
{
	std::string picture = m_state->getAssetDir() + "gLeft.png";
	if (side)
		picture = m_state->getAssetDir() + "gRgiht.png";


	SETCOLOR(m_brush.fill_color, 1.0f, 0.5f, 0.0f);

	m_brush.fill_opacity = 1.0f;
	m_brush.outline_opacity = 0.0f;
	//m_brush.texture = picture;

	if (side) {
		m_pos_x = 0.2f;
		m_pos_y = 5.0f;
	}
	else {
		m_pos_x = 15.8f;
		m_pos_y = 5.0f;
	}
}

void Goal::draw()
{


	graphics::drawRect(m_pos_x, m_pos_y, m_width, m_draw_height, m_brush);
}

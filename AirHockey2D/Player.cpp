#pragma once
#include "Player.h"
#include "sgg/graphics.h"
#include "GameObject.h"
#include "string"
#include "GameState.h"
#include "util.h"
#include "Ball.h"


Player::Player(bool side,const std::string& name)
	: GameObject(name), side(side) 
{
	
	size=0.6;
	real_size = 2 * size;
	m_width = real_size;
	m_height = real_size;

	big = real_size * 0.496f;
	small = real_size * 0.008f;

}

void Player::update(float dt)
{
	float delta_time = dt / 1000.0f;

	


	if (side) {
		if (graphics::getKeyState(graphics::SCANCODE_A) and (m_pos_x - size) > 0.3f)
			m_pos_x -= delta_time * velocity;
			if (graphics::getKeyState(graphics::SCANCODE_D)  and (m_pos_x + size+0.1f) < (m_state->get_width()/2.0f))
			m_pos_x += delta_time * velocity;
			if (graphics::getKeyState(graphics::SCANCODE_W) and (m_pos_y - size) > 1.0f)
			m_pos_y -= delta_time * velocity;
		if (graphics::getKeyState(graphics::SCANCODE_S)and (m_pos_y + size) < m_state->get_height())
			m_pos_y += delta_time * velocity;
	}
	else {
		if (graphics::getKeyState(graphics::SCANCODE_LEFT) and (m_pos_x - size-0.08f) > (m_state->get_width() / 2.0f))
			m_pos_x -= delta_time * velocity;
		if (graphics::getKeyState(graphics::SCANCODE_RIGHT) and (m_pos_x + size) < m_state->get_width()-0.3f)
			m_pos_x += delta_time * velocity;
		if (graphics::getKeyState(graphics::SCANCODE_UP) and (m_pos_y - size) > 1.0f)
			m_pos_y -= delta_time * velocity;
		if (graphics::getKeyState(graphics::SCANCODE_DOWN)and (m_pos_y + size) < m_state->get_height())
			m_pos_y += delta_time * velocity;
	}


	

	top_left = Box(m_pos_x - size + (big / 2.0f), m_pos_y - size + (big / 2.0f), big, big);
	top_right = Box(m_pos_x + size - (big / 2.0f), m_pos_y - size + (big / 2.0f), big, big);
	bottom_left = Box(m_pos_x - size + (big / 2.0f), m_pos_y + size - (big / 2.0f), big, big);
	bottom_right = Box(m_pos_x+size-(big/2.0f), m_pos_y + size - (big / 2.0f), big, big);
	top = Box(m_pos_x, m_pos_y - size + (small / 2.0f),small,small);
	left = Box(m_pos_x-size+ (small / 2.0f), m_pos_y, small, small);
	bottom = Box(m_pos_x, m_pos_y + size - (small / 2.0f), small, small);
	right = Box(m_pos_x+size-(small/2.0f), m_pos_y, small, small); 


}

void Player::init()
{
	std::string picture = m_state->getAssetDir() + "2.png";
	if (side)
		picture = m_state->getAssetDir() + "1.png";

	SETCOLOR(m_brush.fill_color, 1.0f, 1.0f, 1.0f);
	
	m_brush.fill_opacity = 1.0f;
	m_brush.outline_opacity = 0.0f;
	SETCOLOR(m_brush.outline_color, 0.0f, 0.0f, 0.0f);

	m_brush.texture = picture;
	
	start();

	top_left = Box(m_pos_x - size + (big / 2.0f), m_pos_y - size + (big / 2.0f), big, big);
	top_right = Box(m_pos_x + size - (big / 2.0f), m_pos_y - size + (big / 2.0f), big, big);
	bottom_left = Box(m_pos_x - size + (big / 2.0f), m_pos_y + size - (big / 2.0f), big, big);
	bottom_right = Box(m_pos_x + size - (big / 2.0f), m_pos_y + size - (big / 2.0f), big, big);
	top = Box(m_pos_x, m_pos_y - size + (small / 2.0f), small, small);
	left = Box(m_pos_x - size + (small / 2.0f), m_pos_y, small, small);
	bottom = Box(m_pos_x, m_pos_y + size - (small / 2.0f), small, small);
	right = Box(m_pos_x + size - (small / 2.0f), m_pos_y, small, small);
	



}

void Player::draw()
{
	
	graphics::drawRect(m_pos_x, m_pos_y, real_size,real_size, m_brush);	
}

void Player::start()
{
	if (side) {
		m_pos_x = 2.0f;
		m_pos_y = 5.0f;
	
	}
	else {
		m_pos_x = 14.0f;
		m_pos_y = 5.0f;
	}

}

void Player::collision(bool a)
{	
	if (a) {
		m_pos_x = m_pos_x + intersectSideways(*m_state->getBall());

	}

	else {
		
			m_pos_y = m_pos_y + intersectUp(*m_state->getBall());
		
			m_pos_y = m_pos_y + intersectDown(*m_state->getBall());
		
	}
}



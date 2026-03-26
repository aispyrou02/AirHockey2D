#pragma once
#include "Level.h"
#include <list>
#include "util.h" 
#include "Goal.h"
#include "Ball.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <string>



Level::Level(const std::string& name)
	:GameObject(name)
{
}

void Level::update(float dt)
{

	if (dt > 500) {
		return;
	}


	if (point) {
		std::this_thread::sleep_for(std::chrono::seconds(1));
		point = false;
		SETCOLOR(m_brush.fill_color, 1.0f, 1.0f, 1.0f);
	}
	


	for (GameObject* obj : m_gameObjects) {
		if (obj and obj->isActive())
		{
			obj->update(dt);
		}
	}
	 
	check_goal();


	if (m_name == "finishLevel") {
	
		if (graphics::getKeyState(graphics::SCANCODE_RETURN) or graphics::getKeyState(graphics::SCANCODE_KP_ENTER)) {
			graphics::stopMessageLoop();
		}
	}






}


void Level::init()
{
	m_brush.outline_opacity = 0.0f;
	m_brush.fill_opacity = 1.0f;
	SETCOLOR(m_brush.fill_color, 1.0f, 1.0f, 1.0f);
	m_brush.texture = m_state->getAssetDir() + "backround.png";

	m_writing_brush.fill_opacity = 1.0;
	SETCOLOR(m_writing_brush.fill_color, 1.0f, 1.0f, 1.0f);
	SETCOLOR(m_writing_brush2.fill_color, 0.0f, 0.0f, 0.0f);
	

	if (m_state->getPlayer1())    m_gameObjects.push_back(m_state->getPlayer1());
	if (m_state->getPlayer2())    m_gameObjects.push_back(m_state->getPlayer2());
	if (m_state->getBall())       m_gameObjects.push_back(m_state->getBall());
	if (m_state->getGoalLeft())   m_gameObjects.push_back(m_state->getGoalLeft());
	if (m_state->getGoalRight())  m_gameObjects.push_back(m_state->getGoalRight());





	if (m_name == "finishLevel") {

		for (GameObject* obj : m_gameObjects) {
			if (obj) {
				obj->setActive(false);
			}
		}
		

		SETCOLOR(m_winning_brush.fill_color, 1.0f, 1.0f, 1.0f);
		m_winning_brush.outline_opacity = 0.0f;
		m_winning_brush.fill_opacity = 1.0f;


	}





}

void Level::draw()
{
	graphics::drawRect(m_center_x, m_center_y, m_state->get_width(), m_state->get_height() * 8.0f / 9.0f, m_brush);

	std::string score = std::to_string(m_state->scoreL) + " - " + std::to_string(m_state->scoreR);


	
	if(m_state->getPlayer1()->isActive()){ graphics::drawText(0.5f, 1.0f, 0.5f, m_state->getPlayer1()->getName(), m_writing_brush); }

	graphics::drawText(7.58f, 1.0f, 0.5f, score, m_writing_brush);

	if (m_state->getPlayer2()->isActive()) { graphics::drawText(13.55f, 1.0f, 0.5f, m_state->getPlayer2()->getName(), m_writing_brush); }



	for (GameObject* obj : m_gameObjects) {
		if (obj && obj->isActive()) {
			obj->draw();
		}
	}


	if(m_state->getFinito()){

	std::string finalmsg;

		if (m_state->scoreL == 5) {

			SETCOLOR(m_writing_brush2.fill_color, 1.0f, 0.0f, 0.0f);

			m_winning_brush.texture = m_state->getAssetDir() + "1_win.png";

			finalmsg = m_state->getPlayer1()->getName() + " HAS WON THE GAME";
			
			graphics::drawText(5.1f, 4.0f, 0.5f, finalmsg, m_writing_brush2);

			graphics::drawRect(m_center_x, m_center_y + 1.0f, 2.5f, 2.5f, m_winning_brush);


		}
		else {

			SETCOLOR(m_writing_brush2.fill_color, 0.0f, 1.0f, 0.0f);

			m_winning_brush.texture = m_state->getAssetDir() + "2_win.png";

			finalmsg = m_state->getPlayer2()->getName() + " HAS WON THE GAME";

			graphics::drawText(5.1f, 4.0f, 0.5f, finalmsg, m_writing_brush2);

			graphics::drawRect(m_center_x, m_center_y + 1.0f, 2.5f, 2.5f, m_winning_brush);



		}








	}

















}


















void Level::check_goal()
{

	if (m_state->getBall()->intersect(*m_state->getGoalLeft())) {
		made_goal(true);
		return;
	}
	if (m_state->getBall()->intersect(*m_state->getGoalRight())) {
		made_goal(false);
		return;
	}

	
}

void Level::made_goal(bool side)
{
	if (side) {
		m_state->setSR();
		
	}
	else {
		m_state->setSL();
	}
	m_state->getBall()->setSide(side);
	m_state->getBall()->start();
	m_state->getPlayer1()->start();
	m_state->getPlayer2()->start();
	point = true;
	SETCOLOR(m_brush.fill_color, 1.5f, 1.5f, 1.5f);

}





Level::~Level()
{
}










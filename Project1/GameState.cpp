#pragma once
#include "GameState.h"
#include "string"
#include "Level.h"
#include "Player.h"
#include "Goal.h"
#include "Ball.h"


GameState::GameState()
{
}

void GameState::init()
{
	m_current_level = new Level("mainLevel");
	m_player1 = new Player(true,"PLAYER_1");
	m_player2 = new Player(false,"PLAYER_2");
	m_Goal_l = new Goal(true);
	m_Goal_r = new Goal(false);
	m_Ball = new Ball(true);
	m_player1->init();
	m_player2->init();
	m_Goal_l->init();
	m_Goal_r->init();
	m_Ball->init();
	m_current_level->init();

	graphics::preloadBitmaps(m_asset_path);
	graphics::setFont(m_asset_path+"font.ttf");

}

void GameState::draw()
{

	if (m_current_level) {
		m_current_level->draw();
	}



}

void GameState::update(float dt)
{
	if (dt > 500) {
		return;
	}
	if (m_current_level) {
		m_current_level->update(dt);
	}
}

GameState* GameState::getInstance()
{
	if (m_unique == nullptr) {
		m_unique = new GameState();
	}
	
	return m_unique;
}

GameState::~GameState()
{
	if (m_player1) {
		delete m_player1;
	}
	if (m_player2) {
		delete m_player2;
	}
	if (m_current_level) {
		delete m_current_level;
	}
}

std::string GameState::getAssetDir()
{
	return m_asset_path;
}

void GameState::end()
{
	if (scoreL == 5 or scoreR == 5) {

		finito = true;
		m_current_level = new Level("finishLevel");
		m_current_level->init();

	}
	

}

GameState* GameState::m_unique = nullptr;
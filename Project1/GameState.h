#pragma once
#include "sgg/graphics.h"
#include "string"
#include "Player.h"


class GameState {

private:

	std::string m_asset_path = "assets\\";

	float m_canvas_width = 16.0f;
	float m_canvas_height = 9.0f;



	static GameState* m_unique;
	

	class Player * m_player1 = 0;
	class Player* m_player2 = 0;
	class Level* m_current_level = 0;
	class Goal* m_Goal_l = 0;
	class Goal* m_Goal_r = 0;
	class Ball* m_Ball = 0;

	GameState();

	bool finito=false;

public:

	int scoreL = 0;
	int scoreR = 0;

	void init();
	void draw();
	void update(float dt);
	float get_width() { return m_canvas_width; }
	float get_height() { return m_canvas_height; }

	static GameState* getInstance();

	~GameState();

	std::string getAssetDir();

	class Player* getPlayer1() { return m_player1; }
	class Player* getPlayer2() { return m_player2; }
	
	class Goal* getGoalLeft() { return m_Goal_l; }
	class Goal* getGoalRight() { return m_Goal_r; }

	class Ball* getBall() { return m_Ball; }

	class Level* getLevel() { return m_current_level; }

	void setSL() { scoreL++; end(); }
	void setSR() { scoreR++; end(); }

	void end();

	bool getFinito() { return finito; }

};
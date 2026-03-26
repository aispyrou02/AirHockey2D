#pragma once
#include "sgg/graphics.h"
#include "util.h"
#include <stdio.h>
#include "string"
#include "GameState.h"






void init() {
	
	GameState::getInstance()->init();

};


void draw() {

	GameState::getInstance()->draw();
	
};


void update(float dt) {
	GameState::getInstance()->update(dt);
};





int main(int argc, char** argv)
{

	graphics::createWindow(1600, 900, "AirHockey");

	init();

	graphics::setDrawFunction(draw);
	graphics::setUpdateFunction(update);


	graphics::setCanvasSize(GameState::getInstance()->get_width(), GameState::getInstance()->get_height());
	graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);





	
	graphics::startMessageLoop();
	


	return 0;
};
#include "Ball.h"
#include "GameObject.h"
#include "util.h"


Ball::Ball(bool side)
	:  side(side)
{	

	size = 0.4f;
	real_size = 2 * size;
	m_height = real_size;
	m_width = real_size;
	v = 0.009f;
	v2 = 0.006f;
	vv = 0.002f;
}

void Ball::update(float dt)
{
	float offset = 0.0f;
	
	bool a = true;



	m_pos_x = m_pos_x + (velocity_x * dt);
	m_pos_y = m_pos_y + (velocity_y * dt);

	if (intersect(*m_state->getPlayer1())) {
		if (intersect(m_state->getPlayer1()->left)) {
			if (graphics::getKeyState(graphics::SCANCODE_A)) {
				velocity_y = 0.0f;
				velocity_x = -v;
			}
			else {
				velocity_x = -fabs(velocity_x);
			}
		}
		else if (intersect(m_state->getPlayer1()->right)) {

			if (graphics::getKeyState(graphics::SCANCODE_D)) {
				velocity_y = 0.0f;
				velocity_x = v;
			}
			else {
				velocity_x = fabs(velocity_x);

			}


		}
		else if (intersect(m_state->getPlayer1()->top)) {
			a = false;
			if (graphics::getKeyState(graphics::SCANCODE_W)) {
				velocity_y = -v;
				velocity_x = 0.0f;
			}
			else {

				velocity_y = -fabs(velocity_y);
			}

		}
		else if (intersect(m_state->getPlayer1()->bottom) ) {
			a = false;
			if (graphics::getKeyState(graphics::SCANCODE_S)) {
				velocity_y = v;
				velocity_x = 0.0f;
			}
			else {

				velocity_y = fabs(velocity_y);
			}



		}
		else if (intersect(m_state->getPlayer1()->top_left)) {

			if (graphics::getKeyState(graphics::SCANCODE_W) and graphics::getKeyState(graphics::SCANCODE_A)) {
				velocity_y = -v2;
				velocity_x = -v2;
			}
			else if (graphics::getKeyState(graphics::SCANCODE_A)) {
				velocity_x = -v + velocity_x;
				velocity_y = -fabs(velocity_y)-vv;
			}
			else if (graphics::getKeyState(graphics::SCANCODE_W)) {
				velocity_x = -fabs(velocity_x)-vv;
				velocity_y = -v + velocity_y;
			}
			else {
				velocity_x = -fabs(velocity_x);
				velocity_y = -fabs(velocity_y);
			}
		}
		else if (intersect(m_state->getPlayer1()->top_right)) {
			if (graphics::getKeyState(graphics::SCANCODE_W) and graphics::getKeyState(graphics::SCANCODE_D)) {
				velocity_y = -v2;
				velocity_x = v2;
			}
			else if (graphics::getKeyState(graphics::SCANCODE_D)) {
				velocity_x = v + velocity_x ;
				velocity_y = -fabs(velocity_y)-vv;
			}
			else if (graphics::getKeyState(graphics::SCANCODE_W)) {
				velocity_x = fabs(velocity_x)+vv;
				velocity_y = -v + velocity_y;
			}
			else {
				velocity_x = fabs(velocity_x);
				velocity_y = -fabs(velocity_y);
			}
		}
	    else if (intersect(m_state->getPlayer1()->bottom_left)) {
			if (graphics::getKeyState(graphics::SCANCODE_S) and graphics::getKeyState(graphics::SCANCODE_A)) {
				velocity_y = v2;
				velocity_x = -v2;
			}
			else if (graphics::getKeyState(graphics::SCANCODE_A)) {
				velocity_x = -v + velocity_x;
				velocity_y = fabs(velocity_y)+vv;
			}
			else if (graphics::getKeyState(graphics::SCANCODE_S)) {
				velocity_x = -fabs(velocity_x)-vv;
				velocity_y = v;
			}
			else {
				velocity_x = -fabs(velocity_x);
				velocity_y = fabs(velocity_y);
			}
		}
	    else if (intersect(m_state->getPlayer1()->bottom_right)) {
			if (graphics::getKeyState(graphics::SCANCODE_S) and graphics::getKeyState(graphics::SCANCODE_D)) {
				velocity_y = v2;
				velocity_x = v2;
			}
			else if (graphics::getKeyState(graphics::SCANCODE_D)) {
				velocity_x = v ;
				velocity_y = fabs(velocity_y)+vv;
			}
			else if (graphics::getKeyState(graphics::SCANCODE_S)) {
				velocity_x = fabs(velocity_x)+vv;
				velocity_y = v + velocity_y;
			}
			else {
				velocity_x = fabs(velocity_x);
				velocity_y = fabs(velocity_y);
			}
		}
		
		if (a) {

			if (offset = intersectSideways(*m_state->getPlayer1())) {
				m_pos_x = m_pos_x + offset;
				offset = 0.0f;
			}

			else if (offset = intersectDown(*m_state->getPlayer1())) {
				m_pos_y = m_pos_y + offset;
				offset = 0.0f;
			}
			else if (offset = intersectUp(*m_state->getPlayer2())) {
				m_pos_y = m_pos_y + offset;
				offset = 0.0f;
			}
		}
		else {
			if (offset = intersectDown(*m_state->getPlayer1())) {
				m_pos_y = m_pos_y + offset;
				offset = 0.0f;
			}
			else if (offset = intersectUp(*m_state->getPlayer1())) {
				m_pos_y = m_pos_y + offset;
				offset = 0.0f;
			}
			
			else if (offset = intersectSideways(*m_state->getPlayer1())) {
				m_pos_x = m_pos_x + offset;
				offset = 0.0f;
			}
		}
		
		
		

	}
	
	

	float b = true;

	if (intersect(*m_state->getPlayer2())) {

		if (intersect(m_state->getPlayer2()->left)) {
			if (graphics::getKeyState(graphics::SCANCODE_LEFT)) {
				velocity_y = 0.0f;
				velocity_x = -v;
			}
			else {
				velocity_x = -fabs(velocity_x);

			}
		}
		else if (intersect(m_state->getPlayer2()->right)) {
			if (graphics::getKeyState(graphics::SCANCODE_RIGHT)) {
				velocity_y = 0.0f;
				velocity_x = v;
			}
			else {
				velocity_x = fabs(velocity_x);

			}
		}
		else if (intersect(m_state->getPlayer2()->top)) {
			b = false;
			if (graphics::getKeyState(graphics::SCANCODE_UP)) {
				velocity_y = -v;
				velocity_x = 0.0f;
			}
			else {

				velocity_y = -fabs(velocity_y);
			}
		}
		else if (intersect(m_state->getPlayer2()->bottom)) {
			b = false;
			if (graphics::getKeyState(graphics::SCANCODE_DOWN)) {
				velocity_y = v;
				velocity_x = 0.0f;
			}
			else {

				velocity_y = fabs(velocity_y);
			}
		}
		else if (intersect(m_state->getPlayer2()->top_left)) {
			if (graphics::getKeyState(graphics::SCANCODE_UP)) {
				velocity_y = -v2;
				velocity_x = -v2;
			}
			else if (graphics::getKeyState(graphics::SCANCODE_LEFT)) {
				velocity_x = -v + velocity_x ;
				velocity_y = -fabs(velocity_y)-vv;
			}
			else if (graphics::getKeyState(graphics::SCANCODE_UP)) {
				velocity_x = -fabs(velocity_x)-vv;
				velocity_y = -v + velocity_y;
			}
			else {
				velocity_x = -fabs(velocity_x);
				velocity_y = -fabs(velocity_y);
			}
		}
		else if (intersect(m_state->getPlayer2()->top_right)) {
			if (graphics::getKeyState(graphics::SCANCODE_UP)) {
				velocity_y = -v2;
				velocity_x = v2;
			}
			else if (graphics::getKeyState(graphics::SCANCODE_RIGHT)) {
				velocity_x = v + velocity_x;
				velocity_y = -fabs(velocity_y)-vv;
			}
			else if (graphics::getKeyState(graphics::SCANCODE_UP)) {
				velocity_x = fabs(velocity_x)+vv;
				velocity_y = -v + velocity_y;
			}
			else {
				velocity_x = fabs(velocity_x);
				velocity_y = -fabs(velocity_y);
			}
		}
		else if (intersect(m_state->getPlayer2()->bottom_left)) {
			if (graphics::getKeyState(graphics::SCANCODE_DOWN)) {
				velocity_y = v2;
				velocity_x = -v2;
			}
			else if (graphics::getKeyState(graphics::SCANCODE_LEFT)) {
				velocity_x = -v+velocity_x ;
				velocity_y = fabs(velocity_y)+vv;
			}
			else if (graphics::getKeyState(graphics::SCANCODE_DOWN)) {
				velocity_x = -fabs(velocity_x)-vv;
				velocity_y = v + velocity_y;
			}
			else {
				velocity_x = -fabs(velocity_x);
				velocity_y = fabs(velocity_y);
			}
		}
		else if (intersect(m_state->getPlayer2()->bottom_right)) {
			if (graphics::getKeyState(graphics::SCANCODE_DOWN)) {
				velocity_y = v2;
				velocity_x = v2;
			}
			else if (graphics::getKeyState(graphics::SCANCODE_RIGHT)) {
				velocity_x = v + velocity_x;
				velocity_y = fabs(velocity_y)+vv;
			}
			else if (graphics::getKeyState(graphics::SCANCODE_DOWN)) {
				velocity_x = fabs(velocity_x)+vv;
				velocity_y = v + velocity_y;
			}
			else {
				velocity_x = fabs(velocity_x);
				velocity_y = fabs(velocity_y);
			}
		}



		offset = 0.0f;
		if (b) {

			if (offset = intersectSideways(*m_state->getPlayer2())) {
				m_pos_x = m_pos_x + offset;
				offset = 0.0f;
			}

			else if (offset = intersectDown(*m_state->getPlayer2())) {
				m_pos_y = m_pos_y + offset;
				offset = 0.0f;
			}

			else if (offset = intersectUp(*m_state->getPlayer2())) {
				m_pos_y = m_pos_y + offset;
				offset = 0.0f;
			}
		}
		else {

			if (offset = intersectDown(*m_state->getPlayer2())) {
				m_pos_y = m_pos_y + offset;
				offset = 0.0f;
			}
			else if (offset = intersectUp(*m_state->getPlayer2())) {
				m_pos_y = m_pos_y + offset;
				offset = 0.0f;
			}
			else if (offset = intersectSideways(*m_state->getPlayer2())) {
				m_pos_x = m_pos_x + offset;
				
			}	

		}


	}


	
	if(m_pos_x+size+0.1f>m_state->get_width()){
		m_pos_x = m_pos_x + (m_state->get_width()-(m_pos_x + size + 0.1f));
		velocity_x = -velocity_x;
		
	}

	if (m_pos_x - size<0.2f) {
		m_pos_x = m_pos_x + (0.3f - (m_pos_x - size));
		velocity_x = -velocity_x;
		
	}

	if (m_pos_y+size>m_state->get_height()) {
		m_pos_y = m_pos_y + (m_state->get_height() - (m_pos_y + size));
		velocity_y = -velocity_y;
	}

	if (m_pos_y - size < 1.0f){
		m_pos_y = m_pos_y + (1.0f - (m_pos_y - size));
		velocity_y = -velocity_y;
	}

	if (velocity_x > max_vel) velocity_x = max_vel;
	if (velocity_y > max_vel) velocity_y = max_vel;

	if (velocity_x < min_vel) velocity_x = min_vel;
	if (velocity_y < min_vel) velocity_y = min_vel;

	m_state->getPlayer2()->collision(b);
	m_state->getPlayer1()->collision(a);



}

void Ball::init()
{
	std::string picture = m_state->getAssetDir() + "ball.png";

	
	SETCOLOR(m_brush.fill_color, 1.0f, 1.0f, 1.0f);

	m_brush.fill_opacity = 1.0f;
	m_brush.outline_opacity = 0.0f;
	m_brush.texture = picture;




	start();
	
}

void Ball::draw()
{

	graphics::drawRect(m_pos_x, m_pos_y, real_size,real_size, m_brush);
}

void Ball::start()
{
	if (side) {
		m_pos_x = 4.5;
		m_pos_y = 5.0;
	}
	else {
		m_pos_x = 11.5;
		m_pos_y = 5.0;
	}
	velocity_x = 0.0f;
	velocity_y = 0.0f;
}



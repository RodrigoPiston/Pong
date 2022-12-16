#include "Ball.h"

Ball::Ball(float startX, float startY) {
	m_Position.x = startX;
	m_Position.y = startY;

	m_Shape.setRadius(5);
	
	m_Shape.setPosition(m_Position);
}

FloatRect Ball::getPosition() {
	return m_Shape.getGlobalBounds();
}
CircleShape Ball::getShape() {
	return m_Shape;
}

float Ball::getXVelocity() {
	return m_DirectionX;
}

void Ball::reboundSides(){
	m_DirectionX = -m_DirectionX;
}

void Ball::reboundBatOrTop() {
	m_DirectionY = -m_DirectionY;

	// Speed up a little bit on each hit
	m_Speed = m_Speed * 1.1f;
}

void Ball::reboundBottom() {
	m_Position.y = 10;
	m_Position.x = 500;
	m_DirectionY = m_DirectionY * -1;
}

void Ball::resetSpeed() {
	m_Speed = m_OriginalSpeed;
}

void Ball::update(Time dt) {
	// Update the ball's position
	m_Position.y += m_DirectionY * m_Speed * dt.asSeconds();
	m_Position.x += m_DirectionX * m_Speed * dt.asSeconds();

	m_Shape.setPosition(m_Position);
}

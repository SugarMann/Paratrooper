// Includes
#include "Game/Soldier.h"

// Soldier constructors
Soldier::Soldier() {
	m_position = Vector2();
	m_speed = Vector2();
	m_alive = true;
	m_sprite = Texture2D();
}

Soldier::Soldier(const Vector2& position, const Vector2& speed, Texture2D& sprite) {
	m_position = position;
	m_speed = speed;
	m_sprite = sprite;
	m_alive = true;
}


// Setters
void Soldier::setPosition(const Vector2& position)
{
	m_position = position;
}

void Soldier::setSpeed(const Vector2& speed)
{
	m_speed = speed;
}

void Soldier::setTexture(Texture2D& sprite)
{
	m_sprite = sprite;
}
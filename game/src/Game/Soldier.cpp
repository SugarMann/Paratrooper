// Includes
#include "Game/Soldier.h"

// Soldier constructors
Soldier::Soldier() {
	m_position = Vector2();
	m_speed = 0.f;
	m_alive = true;
	m_sprite = Texture2D();
	m_scale = 1.f;
	m_despawn = 50U;
	m_landed = false;
}

Soldier::Soldier(const Vector2& position, const float& speed, Texture2D& sprite, float& scale) {
	m_position = position;
	m_speed = speed;
	m_sprite = sprite;
	m_scale = scale;
	m_alive = true;
	m_despawn = 50U;
	m_landed = false;
}


// Setters
void Soldier::setPosition(const Vector2& position)
{
	m_position = position;
}

void Soldier::setSpeed(const float& speed)
{
	m_speed = speed;
}

void Soldier::setScale(const float& scale)
{
	m_scale = scale;
}

void Soldier::setTexture(Texture2D& sprite)
{
	m_sprite = sprite;
}
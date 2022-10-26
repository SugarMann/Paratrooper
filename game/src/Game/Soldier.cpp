// Includes
#include "Game/Soldier.h"

// Soldier constructors
Soldier::Soldier() {
	m_position = Vector2();
	m_speed = Vector2();
}

Soldier::Soldier(Vector2 position, Vector2 speed) {
	m_position = position;
	m_speed = speed;
}


// Setters
void Soldier::setPosition(Vector2 position)
{
	m_position = position;
}

void Soldier::setSpeed(Vector2 speed)
{
	m_speed = speed;
}

void Soldier::setTexture(Texture2D sprite)
{
	m_sprite = sprite;
}
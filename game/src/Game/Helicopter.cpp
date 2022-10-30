// Includes
#include "Game/Helicotper.h"

// Helicopter constructors
Helicopter::Helicopter() {
	m_position = Vector2();
	m_speed = 0.f;
	m_alive = true;
	m_sprite = Texture2D();
	m_rightOrientation = true;
	m_scale = 1.f;
	m_despawn = 15U;
}

Helicopter::Helicopter(const Vector2& position, const float& speed, Texture2D& sprite, bool rightOrientation, float& scale) {
	m_position = position;
	m_speed = speed;
	m_alive = true;
	m_sprite = sprite;
	m_rightOrientation = rightOrientation;
	m_scale = scale;
	m_despawn = 15U;
}


// Setters
void Helicopter::setPosition(const Vector2& position) 
{
	m_position = position;
}

void Helicopter::setSpeed(const float& speed)
{
	m_speed = speed;
}

void Helicopter::setScale(const float& scale)
{
	m_scale = scale;
}

void Helicopter::setTexture(Texture2D& sprite)
{
	m_sprite = sprite;
}

//Helicopter destructor
Helicopter::~Helicopter()
{
	//TODO: Think about what is here
}
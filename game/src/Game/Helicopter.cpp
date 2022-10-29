// Includes
#include "Game/Helicotper.h"

// Helicopter constructors
Helicopter::Helicopter() {
	m_position = Vector2();
	m_speed = Vector2();
	m_alive = true;
	m_sprite = Texture2D();
}

Helicopter::Helicopter(const Vector2& position, const Vector2& speed, Texture2D& sprite) {
	m_position = position;
	m_speed = speed;
	m_alive = true;
	m_sprite = sprite;
}


// Setters
void Helicopter::setPosition(const Vector2& position) 
{
	m_position = position;
}

void Helicopter::setSpeed(const Vector2& speed)
{
	m_speed = speed;
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
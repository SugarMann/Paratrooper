// Includes
#include "Game/Helicotper.h"

// Helicopter constructors
Helicopter::Helicopter() {
	m_position = Vector2();
	m_speed = Vector2();
}

Helicopter::Helicopter(Vector2 position, Vector2 speed) {
	m_position = position;
	m_speed = speed;
}


// Setters
void Helicopter::setPosition(Vector2 position) 
{
	m_position = position;
}

void Helicopter::setSpeed(Vector2 speed)
{
	m_speed = speed;
}

void Helicopter::setTexture(Texture2D sprite)
{
	m_sprite = sprite;
}

//Helicopter destructor
Helicopter::~Helicopter()
{
	//TODO: Think about what is here
}
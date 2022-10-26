// Includes
#include "Game/Player.h"

// Player constructors
Player::Player() {
	m_position = Vector2();
}

Player::Player(Vector2 position, Vector2 speed) {
	m_position = position;
}


// Setters
void Player::setPosition(Vector2 position)
{
	m_position = position;
}

void Player::setTexture(Texture2D sprite)
{
	m_sprite = sprite;
}
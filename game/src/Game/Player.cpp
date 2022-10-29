// Includes
#include "Game/Player.h"

// Player constructors
Player::Player() {
	m_position = Vector2();
	m_life = 7U;
	m_turretSprite = Texture2D();
	m_playerBodySprite = Texture2D();
}

Player::Player(const Vector2& position, Texture2D& playerBodySprite, Texture2D& turretSprite) {
	m_position = position;
	m_life = 7U;
	m_turretSprite = turretSprite;
	m_playerBodySprite = playerBodySprite;
}


// Setters
void Player::setPosition(const Vector2& position)
{
	m_position = position;
}

void Player::setPlayerBodyTexture(Texture2D& playerBodySprite)
{
	m_playerBodySprite = playerBodySprite;
}

void Player::setTurretTexture(Texture2D& turretSprite)
{
	m_turretSprite = turretSprite;
}
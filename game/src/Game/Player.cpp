// Includes
#include "Game/Player.h"

// Player constructors
Player::Player() {
	m_playerBasePosition = Vector2();
	m_turretPosition = Vector2();
	m_life = 7U;
	m_turretSprite = Texture2D();
	m_playerBaseSprite = Texture2D();
	m_turretRotation = 0;
}

Player::Player(const Vector2& playerBasePosition, const Vector2& turretPosition, Texture2D& playerBodySprite, Texture2D& turretSprite) {
	m_playerBasePosition = playerBasePosition;
	m_turretPosition = turretPosition;
	m_life = 7U;
	m_turretSprite = turretSprite;
	m_playerBaseSprite = playerBodySprite;
	m_turretRotation = 0;
}


// Setters
void Player::setPlayerBasePosition(const Vector2& playerBasePosition)
{
	m_playerBasePosition = playerBasePosition;
}

void Player::setTurretPosition(const Vector2& turretPosition)
{
	m_turretPosition = turretPosition;
}

void Player::setPlayerBaseTexture(Texture2D& playerBaseSprite)
{
	m_playerBaseSprite = playerBaseSprite;
}

void Player::setTurretTexture(Texture2D& turretSprite)
{
	m_turretSprite = turretSprite;
}

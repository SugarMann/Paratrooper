
#ifndef PLAYER_H
#define PLAYER_H

// Includes
#include <stdint.h>

#include "raylib.h"

#ifdef __cplusplus
extern "C" {            // Prevents name mangling of functions
#endif

class Player {

	// Variables
	Vector2 m_playerBasePosition;
	Vector2 m_turretPosition;
	Texture2D m_turretSprite;
	Texture2D m_playerBaseSprite;
	uint8_t m_life;

public:

	// Public variables
	float m_turretRotation;

	// Contructors
	Player();
	Player(const Vector2& playerBasePosition, const Vector2& turretPosition, Texture2D& playerBodySprite, Texture2D& turretSprite);

	// Getters and Setters
	void setPlayerBasePosition(const Vector2& playerBasePosition);
	void setTurretPosition(const Vector2& turretPosition);
	void setPlayerBaseTexture(Texture2D& playerBaseSprite);
	void setTurretTexture(Texture2D& turretSprite);
	Vector2 getPlayerBasePosition() { return m_playerBasePosition; }
	Vector2 getTurretPosition() { return m_turretPosition; }
	Texture2D getPlayerBodyTexture() { return m_playerBaseSprite;  }
	Texture2D getTurretTexture() { return m_turretSprite; }

};

#ifdef __cplusplus
}
#endif

#endif // !PLAYER_H

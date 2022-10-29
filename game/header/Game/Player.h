
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
	Vector2 m_position;
	Texture2D m_turretSprite;
	Texture2D m_playerBodySprite;
	uint8_t m_life;

public:

	// Contructors
	Player();
	Player(const Vector2& position, Texture2D& playerBodySprite, Texture2D& turretSprite);

	// Getters and Setters
	void setPosition(const Vector2& position);
	void setPlayerBodyTexture(Texture2D& playerBodySprite);
	void setTurretTexture(Texture2D& turretSprite);
	Vector2 getPosition() { return m_position; }
	Texture2D getPlayerBodyTexture() { return m_playerBodySprite;  }
	Texture2D getTurretTexture() { return m_turretSprite; }

};

#ifdef __cplusplus
}
#endif

#endif // !PLAYER_H

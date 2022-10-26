
#ifndef PLAYER_H
#define PLAYER_H

// Includes
#include "raylib.h"

#ifdef __cplusplus
extern "C" {            // Prevents name mangling of functions
#endif

class Player {

	// Variables
	Vector2 m_position;
	Texture2D m_sprite;

public:

	// Contructors
	Player();
	Player(Vector2 position, Vector2 speed);

	// Getters and Setters
	void setPosition(Vector2 position);
	void setTexture(Texture2D sprite);
	Vector2 getPosition() { return m_position; }
	Texture2D getTexture() { return m_sprite;  }

};

#ifdef __cplusplus
}
#endif

#endif // !PLAYER_H

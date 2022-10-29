
#ifndef SOLDIER_H
#define SOLDIER_H

// Includes
#include "raylib.h"

#ifdef __cplusplus
extern "C" {            // Prevents name mangling of functions

#endif

class Soldier {

	// Variables
	Vector2 m_position, m_speed;
	Texture2D m_sprite;
	bool m_alive;

public:

	// Contructors
	Soldier();
	Soldier(const Vector2& position, const Vector2& speed, Texture2D& sprite);

	// Getters and Setters
	void setPosition(const Vector2& position);
	void setSpeed(const Vector2& speed);
	void setTexture(Texture2D& sprite);
	Vector2 getPosition() { return m_position; }
	Vector2 getSpeed() { return m_speed; }
	Texture2D getTexture() { return m_sprite; }

};

#ifdef __cplusplus
}
#endif

#endif // !SOLDIER_H
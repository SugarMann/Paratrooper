
#ifndef SOLDIER_H
#define SOLDIER_H

// Includes
#include <stdint.h>

#include "raylib.h"

#ifdef __cplusplus
extern "C" {            // Prevents name mangling of functions

#endif

class Soldier {

	// Variables
	Vector2 m_position;
	Texture2D m_sprite;
	float m_speed;
	float m_scale;

public:

	//Public variables
	uint8_t m_despawn;
	bool m_landed;
	bool m_alive;

	// Contructors
	Soldier();
	Soldier(const Vector2& position, const float& speed, Texture2D& sprite, float& scale);

	// Getters and Setters
	void setPosition(const Vector2& position);
	void setSpeed(const float& speed);
	void setScale(const float& scale);
	void setTexture(Texture2D& sprite);
	Vector2 getPosition() { return m_position; }
	float getSpeed() { return m_speed; }
	float getScale() { return m_scale; }
	Texture2D getTexture() { return m_sprite; }

};

#ifdef __cplusplus
}
#endif

#endif // !SOLDIER_H
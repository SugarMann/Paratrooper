
#ifndef ENEMY_MANAGER_H
#define ENEMY_MANAGER_H

// Includes
#include <vector>

#include "raylib.h"
#include "Game/Helicotper.h"
#include "Game/Soldier.h"
#include "Game/Player.h"

#ifdef __cplusplus
extern "C" {            // Prevents name mangling of functions
#endif

	//----------------------------------------------------------------------------------
	// Enemy Manager Functions Declaration
	//----------------------------------------------------------------------------------
	void createHelicopter(std::vector<Helicopter>& helicopters, float& speed, Texture2D& spriteRight, Texture2D& spriteLeft, float& scale);
	void helicoptersMovement(std::vector<Helicopter>& helicopters);
	void removeHelicopters(std::vector<Helicopter>& helicopters, std::vector<std::pair<Vector2, float>>& projectiles, uint32_t& score);

	void createSoldiers(std::vector<Helicopter>& helicopters, std::vector<Soldier>& soldiers, uint16_t& spawnProbability,
		uint16_t& difficulty, float& speed, Texture2D& sprite, float& scale, Player& player);
	void soldiersMovement(std::vector<Soldier>& soldiers, uint32_t& landed);
	void removeSoldiers(std::vector<Soldier>& soldiers, std::vector<std::pair<Vector2, float>>& projectiles, uint32_t& score);

#ifdef __cplusplus
}
#endif

#endif // !ENEMY_MANAGER_H
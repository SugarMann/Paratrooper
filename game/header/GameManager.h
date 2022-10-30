
#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

// Includes
#include <vector>

#include "Game/Player.h"
#include "Game/Helicotper.h"
#include "Game/Soldier.h"

#ifdef __cplusplus
extern "C" {            // Prevents name mangling of functions
#endif

//----------------------------------------------------------------------------------
// Game logic
//----------------------------------------------------------------------------------
	void turretMovement(Player& player, float limit);
	void createProjectil(Player& player, std::vector<std::pair<Vector2, float>>& projectiles, Vector2& initialPosition);
	void projectilesMovement(std::vector<std::pair<Vector2, float>>& projectiles, float projectileSpeed);
	void removeProjectiles(std::vector<std::pair<Vector2, float>>& projectiles);
	void removeProjectile(std::vector<std::pair<Vector2, float>>& projectiles, std::pair<Vector2, float> projectile);

//----------------------------------------------------------------------------------
// Remove methods declaration
//----------------------------------------------------------------------------------
	void removePlayer(Player player);
	void removeHelicopter(Helicopter helicopter);
	void removeSoldier(Soldier soldier);

#ifdef __cplusplus
}
#endif

#endif // !GAME_MANAGER_H

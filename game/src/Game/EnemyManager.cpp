
// Includes
#include "Game/EnemyManager.h"
#include "GameManager.h"
#include "GlobalGameDefines.h"

//----------------------------------------------------------------------------------
// Enemy Manager Definition (local)
//----------------------------------------------------------------------------------


//----------------------------------------------------------------------------------
// Enemy Manager Functions Definition
//----------------------------------------------------------------------------------
void createHelicopter(std::vector<Helicopter>& helicopters, float& speed, Texture2D& spriteRight, Texture2D& spriteLeft, float& scale)
{
	// 50% of possibilities to get the helicopter orientation
	uint8_t prob = std::rand() % 100U;

	if (prob >= 50U) // Right
	{
		if (prob >= 75U) // Highest position 
		{
			float posX = 0.f - spriteLeft.width * scale;
			float posY = 50.f;
			Helicopter helicopter(Vector2 {posX, posY}, speed, spriteRight, true, scale);
			helicopters.push_back(helicopter);
		}
		else // Lowest position
		{
			float posX = 0.f - spriteLeft.width * scale;
			float posY = 100.f;
			Helicopter helicopter(Vector2{posX, posY}, speed, spriteRight, true, scale);
			helicopters.push_back(helicopter);
		}
	}
	else // From left
	{
		if (prob <= 25U) // Highest position 
		{
			float posX = GetScreenWidth();
			float posY = 50.f;
			Helicopter helicopter(Vector2{posX, posY}, speed, spriteLeft, false, scale);
			helicopters.push_back(helicopter);
		}
		else // Lowest position
		{
			float posX = GetScreenWidth();
			float posY = 100.f;
			Helicopter helicopter(Vector2{posX, posY}, speed, spriteLeft, false, scale);
			helicopters.push_back(helicopter);
		}
	}

}

void helicoptersMovement(std::vector<Helicopter>& helicopters)
{
	for (Helicopter& helicopter : helicopters)
	{
		if (helicopter.m_rightOrientation && helicopter.m_alive)
		{
			// helicopter only moves on x axis
			float newPosX = helicopter.getPosition().x + 1.f * helicopter.getSpeed();
			float newPosY = helicopter.getPosition().y;
			helicopter.setPosition(Vector2 {newPosX, newPosY});
		}
		else if (!helicopter.m_rightOrientation && helicopter.m_alive)
		{
			// helicopter only moves on x axis
			float newPosX = helicopter.getPosition().x - 1.f * helicopter.getSpeed();
			float newPosY = helicopter.getPosition().y;
			helicopter.setPosition(Vector2{ newPosX, newPosY });
		}
	}
}

void removeHelicopters(std::vector<Helicopter>& helicopters, std::vector<std::pair<Vector2, float>>& projectiles, uint32_t& score)
{
	// Remove helicopters out of bounds
	helicopters.erase(
		std::remove_if(
			helicopters.begin(),
			helicopters.end(),
			[](Helicopter& h) -> bool {
				if (h.m_rightOrientation && h.getPosition().x > GetScreenWidth())
					return true;
				else if (!h.m_rightOrientation && h.getPosition().x < (0.f - h.getTexture().width * 0.75f))
					return true;
				else if (h.m_despawn == 0U)
					return true;
				else
					return false;
			}
		),
		helicopters.end()
	);

	// Kill helicopters in same positions than projectiles
	for (Helicopter& helicopter : helicopters)
	{
		for (std::pair<Vector2, float>& projectile : projectiles)
		{
			if (projectile.first.x >= helicopter.getPosition().x && 
				projectile.first.x <= helicopter.getPosition().x + helicopter.getTexture().width * helicopter.getScale())
			{
				if (projectile.first.y >= helicopter.getPosition().y && 
					projectile.first.y <= helicopter.getPosition().y + helicopter.getTexture().height * helicopter.getScale())
				{
					// If the helicopter was alive means player score 10 points and remove THAT bullet
					if (helicopter.m_alive)
					{
						score += 10U;
						removeProjectile(projectiles, projectile);
						PlaySound(fxExplosion);
					}
					// This helicopter is now dead
					helicopter.m_alive = false;
				}
			}
		}
	}

}

void createSoldiers(std::vector<Helicopter>& helicopters, std::vector<Soldier>& soldiers, uint16_t& spawnProbability, 
					uint16_t& difficulty, float& speed, Texture2D& sprite, float& scale, Player& player)
{
	for (Helicopter helicopter : helicopters)
	{
		if (spawnProbability <= difficulty)
		{
			// Update probability of spawn
			spawnProbability = std::rand() % 2000U;

			// Is the heli above player position soldiers doesn't spawn
			if (helicopter.getPosition().x >= player.getPlayerBasePosition().x &&
				helicopter.getPosition().x < player.getPlayerBasePosition().x + player.getPlayerBodyTexture().width * 1.5f)
			{
				continue;
			}
			else if (helicopter.getPosition().x <= 0U ||
					helicopter.getPosition().x >= GetScreenWidth())
			{
				continue;
			}
			else // If it's not, soldiers can deploy
			{
				Soldier newSoldier(helicopter.getPosition(), speed, sprite, scale);
				soldiers.push_back(newSoldier);
			}
		}
		else
		{
			// Update probability of spawn
			spawnProbability = std::rand() % 2000U;
		}
	}
}

void soldiersMovement(std::vector<Soldier>& soldiers, uint32_t& landed)
{
	for (Soldier& soldier : soldiers)
	{
		if (soldier.m_alive && soldier.getPosition().y + soldier.getTexture().height * soldier.getScale() <= GetScreenHeight())
		{
			// soldier only moves on y axis
			float newPosX = soldier.getPosition().x;
			float newPosY = soldier.getPosition().y + 1.f * soldier.getSpeed();
			soldier.setPosition(Vector2{ newPosX, newPosY });
		}
		if (soldier.getPosition().y + soldier.getTexture().height * soldier.getScale() >= GetScreenHeight() && !soldier.m_landed)
		{
			// This soldier landed
			soldier.m_landed = true;
			landed++;
		}
	}
}

void removeSoldiers(std::vector<Soldier>& soldiers, std::vector<std::pair<Vector2, float>>& projectiles, uint32_t& score)
{
	// Despawn soldiers
	soldiers.erase(
		std::remove_if(
			soldiers.begin(),
			soldiers.end(),
			[](Soldier& s) -> bool {
				if (s.m_despawn == 0U)
					return true;
				else
					return false;
			}
		),
		soldiers.end()
	);

	// Kill soldiers in same positions than projectiles
	for (Soldier& soldier : soldiers)
	{
		for (std::pair<Vector2, float>& projectile : projectiles)
		{
			if (projectile.first.x >= soldier.getPosition().x &&
				projectile.first.x <= soldier.getPosition().x + soldier.getTexture().width * soldier.getScale())
			{
				if (projectile.first.y >= soldier.getPosition().y &&
					projectile.first.y <= soldier.getPosition().y + soldier.getTexture().height * soldier.getScale())
				{
					// If soldier was alive means player score 5 points
					if (soldier.m_alive)
					{
						score += 5U;
						removeProjectile(projectiles, projectile);
						PlaySound(fxExplosion);
					}
					// This soldier is now dead
					soldier.m_alive = false;
				}
			}
		}
	}
}
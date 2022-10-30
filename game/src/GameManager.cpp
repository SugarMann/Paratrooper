
// Includes
#include <algorithm>

#include "raylib.h"
#include "GameManager.h"

//----------------------------------------------------------------------------------
// Initialization methods definition
//----------------------------------------------------------------------------------
void turretMovement(Player& player, float limit)
{
    float posX = player.getTurretPosition().x;
    float posY = player.getTurretPosition().y;

    if (IsKeyDown(KEY_D) && player.m_turretRotation<= limit)
    {
        // Update rotation
        player.m_turretRotation += 2.f;
        
        // Update turret position
        if (player.m_turretRotation >= 0)
        {
            posX++;
            posY--;
            player.setTurretPosition(Vector2{ posX, posY });
        }
        else
        {
            posX++;
            posY++;
            player.setTurretPosition(Vector2{ posX, posY });
        }
    }
    if (IsKeyDown(KEY_A) && player.m_turretRotation >= -limit)
    {   
        // Update rotation
        player.m_turretRotation -= 2.f;

        // Update turret position
        if (player.m_turretRotation >= 0)
        {
            posX--;
            posY++;
            player.setTurretPosition(Vector2{ posX, posY });
        }
        else
        {
            posX--;
            posY--;
            player.setTurretPosition(Vector2{ posX, posY });
        }
    }    
}

void createProjectil(Player& player, std::vector<std::pair<Vector2, float>>& projectiles, Vector2& initialPosition)
{   
    Vector2 projectilePos = { initialPosition.x, initialPosition.y };
    std::pair<Vector2, float> projectile = {projectilePos, player.m_turretRotation};
    projectiles.push_back(projectile);
}

void projectilesMovement(std::vector<std::pair<Vector2, float>>& projectiles, float projectileSpeed)
{
    for (std::pair<Vector2, float>& projectile : projectiles)
    {
        // Movement
        // converting degrees to radians
        float x = projectile.second * 3.14159f / 180.f;

        projectile.first.x = projectile.first.x + (projectileSpeed * static_cast<float>(sin(x)));
        projectile.first.y = projectile.first.y - (projectileSpeed * static_cast<float>(cos(x)));
    }
}

void removeProjectiles(std::vector<std::pair<Vector2, float>>& projectiles)
{
    // Out of bounds
    projectiles.erase(
        std::remove_if(
            projectiles.begin(),
            projectiles.end(),
            [](std::pair<Vector2, float>& pr) -> bool {
                if (pr.first.x > GetScreenWidth() || pr.first.y < 0)
                    return true;
                else if (pr.first.y > GetScreenHeight() || pr.first.y < 0)
                    return true;
                else
                    return false;
            }
        ),
        projectiles.end()
    );
}

void removeProjectile(std::vector<std::pair<Vector2, float>>& projectiles, std::pair<Vector2, float> projectile)
{
    // Remove one specific projectile
    for (std::vector<std::pair<Vector2, float>>::iterator iter = projectiles.begin(); iter != projectiles.end(); ++iter)
    {
        if (iter->first.x == projectile.first.x && iter->first.y == projectile.first.y)
        {
            projectiles.erase(iter);
            break;
        }
    }
}

//----------------------------------------------------------------------------------
// Remove methods difinition
//----------------------------------------------------------------------------------
void removePlayer(Player player)
{

}
void removeHelicopter(Helicopter helicopter)
{

}
void removeSoldier(Soldier soldier) {

}
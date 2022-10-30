/**********************************************************************************************
*
*   raylib - Advance Game template
*
*   Gameplay Screen Functions Definitions (Init, Update, Draw, Unload)
*
*   Copyright (c) 2014-2022 Ramon Santamaria (@raysan5)
*
*   This software is provided "as-is", without any express or implied warranty. In no event
*   will the authors be held liable for any damages arising from the use of this software.
*
*   Permission is granted to anyone to use this software for any purpose, including commercial
*   applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*     1. The origin of this software must not be misrepresented; you must not claim that you
*     wrote the original software. If you use this software in a product, an acknowledgment
*     in the product documentation would be appreciated but is not required.
*
*     2. Altered source versions must be plainly marked as such, and must not be misrepresented
*     as being the original software.
*
*     3. This notice may not be removed or altered from any source distribution.
*
**********************************************************************************************/

#include <stdint.h>
#include <string>
#include <chrono>
#include <ctime>
#include <vector>

#include "raylib.h"
#include "Screens/ScreenGameplay.h"
#include "GlobalGameDefines.h"
#include "Game/Player.h"
#include "Game/EnemyManager.h"
#include "Game/Helicotper.h"
#include "Game/Soldier.h"
#include "GameManager.h"

//----------------------------------------------------------------------------------
// Module Variables Definition (local)
//----------------------------------------------------------------------------------

// Gameplay objects
static Player player;
static Soldier soldier;

// Projectiles variables
static std::vector<std::pair<Vector2, float>> projectiles;
static Vector2 projectilInitialPosition;
static float projectileSpeed;

// Helicopter variables
static float helicopterSpeed;
static std::vector<Helicopter> helicopters;
static float helicopterScale;

// Soldier variables
static float soldierSpeed;
static std::vector<Soldier> soldiers;
static float soldierScale;

//Gameplay variables
static uint32_t landed;
static uint16_t framesCounter, infoPosX, infoPosY;
static uint8_t finishScreen;
static std::string stringInfo;

// Time variables
static std::chrono::system_clock::time_point start, end;

// Probability variables
static uint16_t helicopterSpawn;
static uint16_t soldierSpawn;

//Textures
static Texture2D playerBaseSprite, turretSprite, helicopterLeftSprite, helicopterRightSprite, soldierSprite, deadSprite;
static Rectangle sourceRectangle, destRectangle;
static Vector2 origin;

//----------------------------------------------------------------------------------
// Gameplay Screen Functions Definition
//----------------------------------------------------------------------------------

// Gameplay Screen Initialization logic
void InitGameplayScreen(void)
{
    // Initialize variables
    framesCounter = 0U;
    finishScreen = 0U;
    stringInfo = "";
    infoPosX = 0U;
    infoPosY = 0U;
    score = 0U;
    landed = 0U;
    
    projectileSpeed = 5.f;
    helicopterSpeed = 1.5f;
    helicopterScale = 0.75f;
    soldierSpeed = 0.75f;
    soldierScale = 0.75f;

    helicopterSpawn = 999U;
    soldierSpawn = 999U;


    // Load Textures
    playerBaseSprite = LoadTexture("resources/Player/PlayerBody.png");
    turretSprite = LoadTexture("resources/Player/Turret.png");
    helicopterLeftSprite = LoadTexture("resources/Enemies/Helicopter_Left.png");
    helicopterRightSprite = LoadTexture("resources/Enemies/Helicopter_Right.png");
    soldierSprite = LoadTexture("resources/Enemies/Soldier.png");
    deadSprite = LoadTexture("resources/Enemies/Dead.png");
    playerBaseSprite = LoadTexture("resources/Player/PlayerBody.png");
    
    // Start counter for gameplay screen
    start = std::chrono::system_clock::now();

    // Objects initialization
    Vector2 playerBasePosition = { static_cast<int>((GetScreenWidth() / 2) - playerBaseSprite.width / 2), GetScreenHeight() - playerBaseSprite.height * 1.5f};

    Vector2 turretPosition = { static_cast<int>((GetScreenWidth() / 2) + turretSprite.width*1.4f ),
                               static_cast<int>(GetScreenHeight() - playerBaseSprite.height * 1.5f + turretSprite.height / 4 )};

    player = Player(playerBasePosition, turretPosition, playerBaseSprite, turretSprite);
    // Source rectangle (part of the texture to use for drawing)
    sourceRectangle = { 0.0f, 0.0f, static_cast<float>(turretSprite.width), static_cast<float>(turretSprite.height) };
    // Destination rectangle (screen rectangle where drawing part of texture)
    destRectangle = { player.getTurretPosition().x, player.getTurretPosition().y, (float)turretSprite.width, (float)turretSprite.height };
    // Origin of the texture (rotation/scale point), it's relative to destination rectangle size
    origin = { static_cast<float>(turretSprite.width) / 2.f, (float)turretSprite.height };

    // Save initial position for any projectil
    projectilInitialPosition.x = player.getPlayerBasePosition().x + playerBaseSprite.width * 3/4;
    projectilInitialPosition.y = player.getPlayerBasePosition().y + playerBaseSprite.height / 10;

}

// Gameplay Screen Update logic
void UpdateGameplayScreen(void)
{
    //----------------------------------------------------------------------------------
    // Turret logic
    //----------------------------------------------------------------------------------
    turretMovement(player, 90.f);

    // Shoot logic
    projectilesMovement(projectiles, projectileSpeed);
    removeProjectiles(projectiles); // Out of bounds

    if (IsKeyPressed(KEY_SPACE))
    {
        createProjectil(player, projectiles, projectilInitialPosition);

        // Down score
        if (score != 0U)
            score--;
        // Play fx sound
        PlaySound(fxShoot);
    }

    //----------------------------------------------------------------------------------
    // Helicopters logic
    //----------------------------------------------------------------------------------
    // Helicopters spawn
    if (helicopters.size() < static_cast<size_t>(3) && helicopterSpawn <= difficulty)
    {
        // Update probability of spawn
        helicopterSpawn = std::rand() % 1000U;
        // Create helicopter
        createHelicopter(helicopters, helicopterSpeed, helicopterRightSprite, helicopterLeftSprite, helicopterScale);
    }
    else if (helicopters.size() < static_cast<size_t>(3) && helicopterSpawn > difficulty)
    {
        // Update probability of spawn
        helicopterSpawn = std::rand() % 1000U;
    }

    // Helicopters movement
    helicoptersMovement(helicopters);

    // Helicopters despawn
    removeHelicopters(helicopters, projectiles, score); // Out of bounds and killed

    //----------------------------------------------------------------------------------
    // Soldiers logic
    //----------------------------------------------------------------------------------
    // Soldiers spawn
    if (!helicopters.empty())
    {
        // Try to create soldiers
        createSoldiers(helicopters, soldiers, soldierSpawn, difficulty, soldierSpeed, soldierSprite, soldierScale, player);
    }

    // Soldiers movement
    soldiersMovement(soldiers, landed);

    // Helicopters despawn
    removeSoldiers(soldiers, projectiles, score); // Killed by player

    // Press enter or tap to change to ENDING screen
    if (IsKeyPressed(KEY_Q) || landed == 7U)
    {
        finishScreen = 1U;
        PlaySound(fxGameOver);
    }
}

// Gameplay Screen Draw logic
void DrawGameplayScreen(void)
{
    // Draw background
    ClearBackground(BLACK);

    // Add text about score points
    stringInfo = "SCORE: " + std::to_string(score);
    infoPosX = static_cast<uint16_t>(GetScreenWidth() / 12);
    infoPosY = 5U;
    DrawText(stringInfo.c_str(), infoPosX, infoPosY, 22U, PURPLE);

    // Update the elapsed time since the gameplay screen was initialized
    end = std::chrono::system_clock::now();
    gameplayTime = end - start;

    // Add text about time
    stringInfo = "TIME: " + std::to_string(gameplayTime.count());
    infoPosX = static_cast<uint16_t>(GetScreenWidth() / 2.75f);
    infoPosY = 5U;
    DrawText(stringInfo.c_str(), infoPosX, infoPosY, 22U, WHITE);

    // Add text about landed soldiers
    stringInfo = "LANDED: " + std::to_string(landed);
    infoPosX = static_cast<uint16_t>(GetScreenWidth() / 1.35f);
    infoPosY = 5U;
    DrawText(stringInfo.c_str(), infoPosX, infoPosY, 22U, PURPLE);

    //Draw helicopters
    for (Helicopter& helicopter : helicopters)
    {
        if (!helicopter.m_alive) // is dead
        {
            // Update internal counter for despawn helicopter
            helicopter.m_despawn--;
            // Draw dead sprite
            DrawTextureEx(deadSprite, helicopter.getPosition(), 0.f, helicopter.getScale(), WHITE);
        }
        else // is alive
        {
            DrawTextureEx(helicopter.getTexture(), helicopter.getPosition(), 0.f, helicopter.getScale(), WHITE);
        }
    }

    // Draw soldiers
    for (Soldier& soldier : soldiers)
    {
        if (!soldier.m_alive) // is dead
        {
            // Update internal counter for despawn helicopter
            soldier.m_despawn--;
            // Draw dead sprite
            DrawTextureEx(deadSprite, soldier.getPosition(), 0.f, soldier.getScale(), WHITE);
        }
        else // is alive
        {
            DrawTextureEx(soldier.getTexture(), soldier.getPosition(), 0.f, soldier.getScale(), WHITE);
        }
    }

    //Draw Projectiles
    for (std::pair<Vector2, float>& projectile : projectiles)
    {
        DrawCircleV(projectile.first, 2.f, WHITE);
    }

    // Draw player base and turret
    DrawTexturePro(turretSprite, sourceRectangle, destRectangle, origin, player.m_turretRotation, WHITE);
    DrawTextureEx(playerBaseSprite, player.getPlayerBasePosition(), 0.f, 1.5f, WHITE);
    
}

// Gameplay Screen Unload logic
void UnloadGameplayScreen(void)
{
    UnloadTexture(playerBaseSprite);
    UnloadTexture(turretSprite);
    UnloadTexture(helicopterLeftSprite);
    UnloadTexture(helicopterRightSprite);
    UnloadTexture(soldierSprite);
    UnloadTexture(deadSprite);
    helicopters.clear();
    soldiers.clear();
    projectiles.clear();
}

// Gameplay Screen should finish?
int FinishGameplayScreen(void)
{
    return finishScreen;
}
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

#include "raylib.h"
#include "Screens\ScreenGameplay.h"
#include "GlobalGameDefines.h"

//----------------------------------------------------------------------------------
// Module Variables Definition (local)
//----------------------------------------------------------------------------------
static int framesCounter, finishScreen;
std::chrono::system_clock::time_point start, end;
std::chrono::duration<double> elapsedTime;
uint32_t score;
uint32_t landed;

//----------------------------------------------------------------------------------
// Gameplay Screen Functions Definition
//----------------------------------------------------------------------------------

// Gameplay Screen Initialization logic
void InitGameplayScreen(void)
{
    // TODO: Initialize GAMEPLAY screen variables here!
    framesCounter = 0;
    finishScreen = 0;
    score = 0U;
    landed = 0U;
    start = std::chrono::system_clock::now();
}

// Gameplay Screen Update logic
void UpdateGameplayScreen(void)
{

    // Press enter or tap to change to ENDING screen
    if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
    {
        finishScreen = 1;
        PlaySound(fxCoin);
    }
}

// Gameplay Screen Draw logic
void DrawGameplayScreen(void)
{
    // Draw background
    ClearBackground(BLACK);

    // Add text about score points
    std::string stringInfo = "SCORE: " + std::to_string(score);
    uint16_t infoPosX = static_cast<uint16_t>(GetScreenWidth() / 12);
    uint16_t infoPosY = 5U;
    DrawText(stringInfo.c_str(), infoPosX, infoPosY, 22U, PURPLE);

    // Update the elapsed time since the gameplay screen was initialized
    end = std::chrono::system_clock::now();
    elapsedTime = end - start;

    // Add text about time
    stringInfo = "TIME: " + std::to_string(elapsedTime.count());
    infoPosX = static_cast<uint16_t>(GetScreenWidth() / 2.75f);
    infoPosY = 5U;
    DrawText(stringInfo.c_str(), infoPosX, infoPosY, 22U, WHITE);

    // Add text about landed soldiers
    stringInfo = "LANDED: " + std::to_string(landed);
    infoPosX = static_cast<uint16_t>(GetScreenWidth() / 1.35f);
    infoPosY = 5U;
    DrawText(stringInfo.c_str(), infoPosX, infoPosY, 22U, PURPLE);

}

// Gameplay Screen Unload logic
void UnloadGameplayScreen(void)
{
    // TODO: Unload GAMEPLAY screen variables here!
}

// Gameplay Screen should finish?
int FinishGameplayScreen(void)
{
    return finishScreen;
}
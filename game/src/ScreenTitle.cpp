/**********************************************************************************************
*
*   raylib - Advance Game template
*
*   Title Screen Functions Definitions (Init, Update, Draw, Unload)
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

#include "raylib.h"
#include "Screens/ScreenTitle.h"
#include "GlobalGameDefines.h"

//----------------------------------------------------------------------------------
// Module Variables Definition (local)
//----------------------------------------------------------------------------------
static int framesCounter = 0;
static int finishScreen = 0;

//----------------------------------------------------------------------------------
// Title Screen Functions Definition
//----------------------------------------------------------------------------------

// Title Screen Initialization logic
void InitTitleScreen(void)
{
    // TODO: Initialize TITLE screen variables here!
    framesCounter = 0;
    finishScreen = 0;
}

// Title Screen Update logic
void UpdateTitleScreen(void)
{
    // TODO: Update TITLE screen variables here!

    // Press enter or tap to change to GAMEPLAY screen
    if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
    {
        finishScreen = 2;   // GAMEPLAY
        PlaySound(fxCoin);
    }
    else if (IsKeyPressed(KEY_O))
    {
        finishScreen = 1; // OPTIONS
        PlaySound(fxCoin);
    }
}

// Title Screen Draw logic
void DrawTitleScreen(void)
{
    // Draw background
    ClearBackground(BLACK);
    // Load and draw title image
    Texture2D titleTexture = LoadTexture("resources/Menus/Title.png");
    DrawTexture(titleTexture, GetScreenWidth() / 2 - titleTexture.width / 2, GetScreenHeight() / 4 - titleTexture.height / 2, WHITE);

    // Add text about menu information
    std::string info = " Press Enter for Playing\nPress 'O' for Instructions";
    uint16_t infoPosX = static_cast<uint16_t>(GetScreenWidth() / 3.5f);
    uint16_t infoPosY = static_cast<uint16_t>(GetScreenHeight() / 1.5f);
    DrawText(info.c_str(), infoPosX, infoPosY, 22U, WHITE);

    // Add author's name texture 
    std::string author = "     by\n Carlos C.";
    uint16_t authorPosX = static_cast<uint16_t>(GetScreenWidth() / 2.5f);
    uint16_t authorPosY = static_cast<uint16_t>(GetScreenHeight() / 2.25f);
    DrawText(author.c_str(), authorPosX, authorPosY, 18U, WHITE);
}

// Title Screen Unload logic
void UnloadTitleScreen(void)
{
    // TODO: Unload TITLE screen variables here!
}

// Title Screen should finish?
int FinishTitleScreen(void)
{
    return finishScreen;
}
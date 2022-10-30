
#ifndef GLOBAL_GAME_DEFINES_H
#define GLOBAL_GAME_DEFINES_H

#include <stdint.h>
#include <chrono>

//----------------------------------------------------------------------------------
// Types and Structures Definition
//----------------------------------------------------------------------------------
typedef enum GameScreen { LOGO = 0, TITLE, OPTIONS, GAMEPLAY, ENDING } GameScreen;

//----------------------------------------------------------------------------------
// Global Variables Declaration (shared by several modules)
//----------------------------------------------------------------------------------
extern GameScreen currentScreen;
extern Font font;
extern Music introMusic;
extern Sound fxCoin;
extern Sound fxShoot;
extern Sound fxGameOver;
extern Sound fxExplosion;

extern uint32_t score;
extern uint16_t difficulty;
extern std::chrono::duration<double> gameplayTime;

#endif // GLOBAL_GAME_DEFINES_H
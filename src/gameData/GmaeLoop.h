#pragma once

#include "objects/Player.h"
#include "objects/Obstacle.h"

// inicializa todo
void InitAll(Player& player, Obstacle& obstacle);

// dibuja el player y lso obstáculos
void DrawAll(Player player, Obstacle obstacle);

// contiene el loop del juego
void GameLoop();
#pragma once

#include "objects/Player.h"
#include "objects/Obstacle.h"

// inicializa todo
void InitAll(Player& player, Obstacle& obstacle1, Obstacle& obstacle2);

// contiene el loop del juego
void GameLoop();
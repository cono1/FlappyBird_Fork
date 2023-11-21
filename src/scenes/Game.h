#pragma once

#include "raylib.h"

#include "Menu.h"
#include "objects/Player.h"
#include "objects/Obstacle.h"

namespace game
{
// dibuja el player y lso obstáculos
void DrawObjects(Player player, Obstacle obstacle1, Obstacle obstacle2);
void DrawObstacles(Obstacle& obstacle1, Obstacle& obstacle2);

// resetea el juego
void ResetGame(Player& player, Obstacle& obstacle1, Obstacle& obstacle2, bool& returnToMenu);

// updatea el juego
void Update(Player& player, Obstacle& obstacle1, Obstacle& obstacle2, bool returnToMenu);
}
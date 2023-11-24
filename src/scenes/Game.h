#pragma once

#include "raylib.h"

#include "Menu.h"
#include "objects/Player.h"
#include "objects/Obstacle.h"

namespace game
{
void InitGameObjects();

// dibuja el player y lso obstáculos
void DrawObjectsHitboxes(Player player, Obstacle obstacle1, Obstacle obstacle2);
void DrawObstacles();
void DrawPlayer(bool isSinglePlayer);

void Update(bool& returnToMenu, Screen& scene, bool isSinglePlayer);

void DeInitGame();
}
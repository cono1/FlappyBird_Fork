#pragma once

#include "raylib.h"

#include "Menu.h"
#include "objects/Player.h"
#include "objects/Obstacle.h"

namespace game
{
// dibuja el player y lso obstáculos
void DrawObjectsHitboxes(Player player, Obstacle obstacle1, Obstacle obstacle2);
void DrawObstacles(Obstacle& obstacle1, Obstacle& obstacle2);
void DrawPlayer(Player player);
void DrawScore();

// updatea el juego
void Update(Player& player, Obstacle& obstacle1, Obstacle& obstacle2, bool& returnToMenu);
void Update(Player& player1, Player& player2, Obstacle& obstacle1, Obstacle& obstacle2, bool& returnToMenu);
}
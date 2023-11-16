#pragma once

#include "Menu.h"

#include "objects/Player.h"
#include "objects/Obstacle.h"

#include "raylib.h"

// dibuja el player y lso obstáculos
void DrawObjects(Player player, Color playerColor, Obstacle obstacle1, Obstacle obstacle2);

void Update(Player& player, Color& playerColor, Obstacle& obstacle1, Obstacle& obstacle2, Texture2D& foreground, Texture2D& midground, Texture2D& playerDown, Texture2D& playerUp, Texture2D& obstacleUp, Texture2D& obstacleDown, float& scrollingFore, float& scrollingBack);
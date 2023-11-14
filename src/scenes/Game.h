#pragma once

#include "Menu.h"

#include "objects/Player.h"
#include "objects/Obstacle.h"

#include "raylib.h"

// dibuja el player y lso obstáculos
void DrawObjects(Player player, Obstacle obstacle1, Obstacle obstacle2);

void Update(Player& player, Obstacle& obstacle1, Obstacle& obstacle2, Texture2D& foreground, Texture2D& midground, float& scrollingFore, float& scrollingMid);
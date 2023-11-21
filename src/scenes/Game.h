#pragma once

#include "Menu.h"

#include "objects/Player.h"
#include "objects/Obstacle.h"

#include "raylib.h"

namespace game
{
// dibuja el player y lso obstáculos
void DrawObjects(Player player, Obstacle obstacle1, Obstacle obstacle2);

// resetea el juego
void ResetGame(Player& player, Obstacle& obstacle1, Obstacle& obstacle2, bool& returnToMenu);

// updatea el juego
void Update(Player& player, Obstacle& obstacle1, Obstacle& obstacle2,
	Texture2D& foreground, Texture2D& midground,
	float& scrollingFore, float& scrollingBack, bool returnToMenu);
}
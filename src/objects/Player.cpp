#include "Player.h"

#include "raylib.h"

void InitPlayer(Player& player)
{
	player.initPosX = 50;
	player.initPosY = static_cast<float>(GetScreenHeight() / 2);

	player.posX = player.initPosX;
	player.posY = player.initPosY;

	player.speed = 10.0f;

	player.width = 20;
	player.height = 20;
}
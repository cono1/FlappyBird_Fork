#include "Player.h"

#include "raylib.h"

namespace game
{
void InitPlayer(Player& player)
{
	player.initPosX = 50;
	player.initPosY = static_cast<float>(GetScreenHeight() / 2);

	player.posX = player.initPosX;
	player.posY = player.initPosY;

	player.speed = 200.0f;

	player.width = 40;
	player.height = 60;

	player.fall = false;
}

void ResetPlayer(Player& player)
{
	player.initPosX = 50;
	player.initPosY = static_cast<float>(GetScreenHeight() / 2);

	player.posX = player.initPosX;
	player.posY = player.initPosY;

	player.fall = false;
}
}
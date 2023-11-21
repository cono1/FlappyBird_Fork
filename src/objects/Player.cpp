#include "Player.h"

namespace game
{
void InitPlayer(Player& player, Vector2 initPos)
{
	player.initPosX = initPos.x;
	player.initPosY = initPos.y;

	player.posX = player.initPosX;
	player.posY = player.initPosY;

	player.speed = 200.0f;

	player.width = 40;
	player.height = 60;

	player.fall = false;
	player.isFlying = false;

	player.color = RED;
	player.playerDownTexture = LoadTexture("res/assets/player/pumpkinDown.png");
	player.playerUpTexture = LoadTexture("res/assets/player/pumpkinUp.png");
}

void ResetPlayer(Player& player)
{
	player.posX = player.initPosX;
	player.posY = player.initPosY;

	player.fall = false;
}

void DeInitPlayer(Player& player)
{
	UnloadTexture(player.playerDownTexture);
	UnloadTexture(player.playerUpTexture);
}
}
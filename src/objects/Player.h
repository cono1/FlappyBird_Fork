#pragma once

#include "raylib.h"

namespace game
{
struct Player
{
	float initPosX;
	float initPosY;

	float posX;
	float posY;

	float speed;

	int width;
	int height;

	bool fall;
	bool isFlying;

	Color color;
	Texture2D playerDownTexture;
	Texture2D playerUpTexture;
};

// inicializa el jugador
void InitPlayer(Player& player, Vector2 initPos);

// resetea la posición del jugador
void ResetPlayer(Player& player);

void DeInitPlayer(Player& player);
}
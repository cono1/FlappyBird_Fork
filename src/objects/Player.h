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

	Color color;
	Texture2D playerDown;
	Texture2D playerUp;
};

// inicializa el jugador
void InitPlayer(Player& player);

// resetea la posición del jugador
void ResetPlayer(Player& player);

void DeInitPlayer(Player& player);
}
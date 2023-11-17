#pragma once

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
};

// inicializa el jugador
void InitPlayer(Player& player);

// resetea la posición del jugador
void ResetPlayer(Player& player);
}
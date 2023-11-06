#pragma once

struct Player
{
	float initPosX;
	float initPosY;

	float posX;
	float posY;

	float speed;

	int width;
	int height;
};

void InitPlayer(Player& player);
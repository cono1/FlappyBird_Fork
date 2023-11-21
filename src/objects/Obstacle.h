#pragma once

#include "raylib.h"

namespace game
{
struct Obstacle
{
	float initPosX;
	float initPosY;

	float posY;
	float posX;

	int width;
	int height;

	float speed;

	Texture2D obstacleUpTexture;
	Texture2D obstacleDownTexture;
};

// inicializa los obst�culos
void InitObstacle(Obstacle& obstacle, float posY, int height);

// resetea la posicion del obst�culo
void ResetObstacle(Obstacle& obstacle, float posY, int height);

void DeInitObstacle(Obstacle& obstacle);
}
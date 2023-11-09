#include "Obstacle.h"

#include "raylib.h"

void InitObstacle(Obstacle& obstacle)
{
	obstacle.initPosX = static_cast<float>(GetScreenWidth() - 40);
	obstacle.initPosY = 0.0f;

	obstacle.posX = obstacle.initPosX;
	obstacle.posY = obstacle.initPosY;

	obstacle.width = 60;
	obstacle.height = 300;

	obstacle.speed = 250.0f;
}

void ResetObstaclePosition(Obstacle& obstacle)
{
	obstacle.initPosX = static_cast<float>(GetScreenWidth() - 40);
	obstacle.initPosY = 0.0f;

	obstacle.posX = obstacle.initPosX;
	obstacle.posY = obstacle.initPosY;

	obstacle.height = 300;
}
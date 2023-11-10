#include "Obstacle.h"

#include "raylib.h"

void InitObstacle(Obstacle& obstacle, float posY, int height)
{
	obstacle.initPosX = static_cast<float>(GetScreenWidth() - 40);
	obstacle.initPosY = posY;

	obstacle.posX = obstacle.initPosX;
	obstacle.posY = obstacle.initPosY;

	obstacle.width = 60;
	obstacle.height = height;

	obstacle.speed = 250.0f;
}

void ResetObstaclePosition(Obstacle& obstacle, float posY, int height)
{
	obstacle.initPosX = static_cast<float>(GetScreenWidth() - 40);
	obstacle.initPosY = posY;

	obstacle.posX = obstacle.initPosX;
	obstacle.posY = obstacle.initPosY;

	obstacle.height = height;
}
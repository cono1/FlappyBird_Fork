#include "Obstacle.h"

#include "raylib.h"

namespace game
{
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

void ResetObstacle(Obstacle& obstacle, float posY, int height)
{
	obstacle.initPosX = static_cast<float>(GetScreenWidth() - 40);
	obstacle.initPosY = posY;

	obstacle.posX = obstacle.initPosX;
	obstacle.posY = obstacle.initPosY;

	obstacle.height = height;
}
}
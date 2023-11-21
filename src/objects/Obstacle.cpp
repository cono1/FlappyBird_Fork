#include "Obstacle.h"

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

	obstacle.obstacleUpTexture = LoadTexture("res/assets/obstacles/wood.png");
	obstacle.obstacleDownTexture = LoadTexture("res/assets/obstacles/wood.png");
}

void ResetObstacle(Obstacle& obstacle, float posY, int height)
{
	obstacle.initPosX = static_cast<float>(GetScreenWidth() - 40);
	obstacle.initPosY = posY;

	obstacle.posX = obstacle.initPosX;
	obstacle.posY = obstacle.initPosY;

	obstacle.height = height;
}

void DeInitObstacle(Obstacle& obstacle)
{
	UnloadTexture(obstacle.obstacleDownTexture);
	UnloadTexture(obstacle.obstacleUpTexture);
}
}
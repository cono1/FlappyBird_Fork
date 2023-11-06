#include "Obstacle.h"

#include "raylib.h"

void InitObstacle(Obstacle& obstacle)
{
	obstacle.posX = GetScreenWidth() - 40;
	obstacle.posY = GetScreenHeight() / 2;

	obstacle.width = 60;
	obstacle.height = 300;
}
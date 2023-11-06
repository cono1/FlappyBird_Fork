#pragma once

struct Obstacle
{
	int posY;
	int posX;

	int width;
	int height;
};

void InitObstacle(Obstacle& obstacle);
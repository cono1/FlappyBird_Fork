#pragma once

struct Obstacle
{
	float initPosX;
	float initPosY;

	float posY;
	float posX;

	int width;
	int height;

	float speed;
};

void InitObstacle(Obstacle& obstacle);
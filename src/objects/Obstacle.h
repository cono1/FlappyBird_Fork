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

// inicializa los obstáculos
void InitObstacle(Obstacle& obstacle);

// resetea la posicion del obstáculo
void ResetObstaclePosition(Obstacle& obstacle);
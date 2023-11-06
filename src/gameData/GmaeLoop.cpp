#include "GmaeLoop.h"

#include "raylib.h"
#include <iostream>

using namespace std;

void InitAll(Player& player, Obstacle& obstacle)
{
	const int screenWidth = 1080;
	const int screenHeight = 720;

	InitWindow(screenWidth, screenHeight, "Flappy Bird");

	InitPlayer(player);
	InitObstacle(obstacle);
}

void DrawAll(Player player, Obstacle obstacle)
{
	DrawRectangle(player.posX, player.posY, player.width, player.height, RED);

	DrawRectangle(obstacle.posX, obstacle.posY, obstacle.width, obstacle.height, ORANGE);
}

void PlayerMovement(Player& player)
{
	if (IsKeyDown(KEY_W))
	{
		player.posY -= player.speed * GetFrameTime();
	}

	else if (IsKeyDown(KEY_S))
	{
		player.posY += player.speed * GetFrameTime();
	}
}

void GameLoop()
{
	Player player;

	Obstacle obstacle;

	InitAll(player, obstacle);

	while (!WindowShouldClose())
	{
		SetExitKey(NULL);

		PlayerMovement(player);

		BeginDrawing();

		DrawAll(player,obstacle);

		ClearBackground(DARKGREEN);

		EndDrawing();
	}

	CloseWindow();

	
}
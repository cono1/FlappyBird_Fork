#include "GmaeLoop.h"

#include "raylib.h"
#include <iostream>

using namespace std;

void InitAll(Player& player, Obstacle& obstacle)
{
	srand(static_cast<unsigned int>(time(NULL)));

	const int screenWidth = 1080;
	const int screenHeight = 720;

	InitWindow(screenWidth, screenHeight, "Flappy Bird 0.1");

	InitPlayer(player);
	InitObstacle(obstacle);
}

void DrawAll(Player player, Obstacle obstacle)
{
	DrawRectangle(static_cast<int>(player.posX), static_cast<int>(player.posY), player.width, player.height, RED);

	DrawRectangle(static_cast<int>(obstacle.posX), static_cast<int>(obstacle.posY), obstacle.width, obstacle.height, ORANGE);
}

// mov del jugador
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

// mov del obstáculo
void ObstacleMovement(Obstacle& obstacle, Player player)
{
	obstacle.posX -= obstacle.speed * GetFrameTime();

	if (obstacle.posX <= 0)
	{
		obstacle.posX = obstacle.initPosX;

		obstacle.height = rand() % GetScreenHeight() + player.height;
	}
}

// colision del juagador con el obstáculo
void PlayerObstacleCollision(Player& player, Obstacle& obstacle)
{
	if ((player.posX + player.width >= obstacle.posX) &&
		(player.posX <= obstacle.posX + obstacle.width) &&
		(player.posY + player.height >= obstacle.posY) &&
		(player.posY <= obstacle.posY + obstacle.height))
	{
		ResetObstaclePosition(obstacle);
		ResetPlayerPosition(player);
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

		ObstacleMovement(obstacle, player);

		PlayerObstacleCollision(player, obstacle);

		BeginDrawing();

		DrawText("0.1", GetScreenWidth() - 50, GetScreenHeight() - 40, 40, WHITE);
		
		DrawAll(player,obstacle);

		ClearBackground(DARKGREEN);

		EndDrawing();
	}

	CloseWindow();

	
}
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

// carga las texturas
void InitTextures(Texture2D& foreground, Texture2D& midground)
{
	foreground = LoadTexture("res/assets/background/cyberpunk_street_foreground.png");
	midground = LoadTexture("res/assets/background/cyberpunk_street_midground.png");
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

	Texture2D foreground;
	Texture2D midground;

	InitAll(player, obstacle);

	InitTextures(foreground, midground);

	float scrollingFore = 0.0f;
	float scrollingMid = 0.0f;

	while (!WindowShouldClose())
	{
		SetExitKey(NULL);

		scrollingFore -= 100.0f * GetFrameTime();
		scrollingMid -= 50.0f * GetFrameTime();

		if (scrollingFore <= -foreground.width * 2) scrollingFore = 0;
		if (scrollingMid <= -midground.width * 2) scrollingMid = 0;

		PlayerMovement(player);

		ObstacleMovement(obstacle, player);

		PlayerObstacleCollision(player, obstacle);

		BeginDrawing();

		DrawTextureEx(midground, Vector2 { scrollingMid, 300 }, 0.0f, 2.0f, WHITE);
		DrawTextureEx(midground, Vector2 { midground.width * 2 + scrollingMid, 300 }, 0.0f, 2.0f, WHITE);

		DrawTextureEx(foreground, Vector2 { scrollingFore, 350 }, 0.0f, 2.0f, WHITE);
		DrawTextureEx(foreground, Vector2 { foreground.width * 2 + scrollingFore, 350 }, 0.0f, 2.0f, WHITE);

		DrawText("0.1", GetScreenWidth() - 50, GetScreenHeight() - 40, 40, WHITE);
		
		DrawAll(player,obstacle);

		ClearBackground(DARKGREEN);

		EndDrawing();
	}

	UnloadTexture(foreground);

	CloseWindow();

	
}
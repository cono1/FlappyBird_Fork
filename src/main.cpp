#include "objects/Player.h"
#include "objects/Obstacle.h"

#include "raylib.h"

int main()
{
	const int screenWidth = 1080;
	const int screenHeight = 720;

	Player player;

	Obstacle obstacle;

	InitWindow(screenWidth, screenHeight, "Flappy Bird");

	InitPlayer(player);
	InitObstacle(obstacle);

	while(!WindowShouldClose())
	{
		SetExitKey(NULL);

		BeginDrawing();

		DrawRectangle(player.posX, player.posY, player.width, player.height, RED);

		DrawRectangle(obstacle.posX, obstacle.posY, obstacle.width, obstacle.height, ORANGE);

		ClearBackground(DARKGREEN);
		
		EndDrawing();
	}

	CloseWindow();

	return 0;
}
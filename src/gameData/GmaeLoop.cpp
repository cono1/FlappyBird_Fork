#include "GmaeLoop.h"

#include "scenes/Menu.h"
#include "scenes/Game.h"
#include "scenes/Credits.h"

#include "raylib.h"
#include <iostream>

using namespace std;

void InitAll(Player& player, Obstacle& obstacle1, Obstacle& obstacle2)
{
	srand(static_cast<unsigned int>(time(NULL)));

	const int screenWidth = 1080;
	const int screenHeight = 720;

	InitWindow(screenWidth, screenHeight, "Flappy Bird 0.1");

	InitPlayer(player);
	InitObstacle(obstacle1, 0.0f, 300);
	InitObstacle(obstacle2, static_cast<float>(GetScreenHeight() / 2 + player.height), GetScreenHeight());
}

// carga las texturas
void InitTextures(Texture2D& foreground, Texture2D& background,
	Texture2D& playerDown, Texture2D& playerUp, Texture2D& obstacleUp, Texture2D& obstacleDown)
{
	foreground = LoadTexture("res/assets/background/forestBack.png");
	background = LoadTexture("res/assets/background/forestFore.png");

	playerDown = LoadTexture("res/assets/player/pumpkinDown.png");
	playerUp = LoadTexture("res/assets/player/pumpkinUp.png");

	obstacleUp = LoadTexture("res/assets/obstacles/wood.png");
	obstacleDown = LoadTexture("res/assets/obstacles/wood.png");
}

void GameLoop()
{
	Screen screen = Screen::MENU;

	Player player;
	Color playerColor = RED;

	Obstacle obstacle1;
	Obstacle obstacle2;

	Texture2D foreground;
	Texture2D background;

	Texture2D playerUp;
	Texture2D playerDown;

	Texture2D obstacleUp;
	Texture2D obstacleDown;

	float scrollingFore = 0.0f;
	float scrollingBack = 0.0f;

	bool returnToMenu = false;

	InitAll(player, obstacle1, obstacle2);
	InitTextures(foreground, background, playerDown, playerUp, obstacleUp,obstacleDown);

	while (!WindowShouldClose())
	{
		SetExitKey(NULL);

		switch (screen)
		{
		case Screen::MENU:
			DrawMenu(screen);
			break;
		case Screen::GAME:
			ResetGame(player, obstacle1, obstacle2, returnToMenu);
			Update(player, playerColor, obstacle1, obstacle2, foreground, background, playerDown, playerUp, obstacleUp, obstacleDown, scrollingFore, scrollingBack, returnToMenu);
			break;
		case Screen::CREDITS:
			break;
		}

		BeginDrawing();

		switch (screen)
		{
		case Screen::MENU:
			break;
		case Screen::GAME:
			//DrawObjects(player, playerColor, obstacle1, obstacle2);
			DrawReturnButton(screen, returnToMenu);
			break;
		case Screen::CREDITS:
			DrawCredits();
			DrawReturnButton(screen, returnToMenu);
			break;
		}

		ClearBackground(DARKGREEN);

		EndDrawing();
	}

	UnloadTexture(foreground);

	CloseWindow();


}
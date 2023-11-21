#include "GameLoop.h"

#include <iostream>

#include "raylib.h"

#include "scenes/Menu.h"
#include "scenes/Game.h"
#include "scenes/Credits.h"
#include "objects/Parallax.h"

using namespace std;

namespace game
{
void InitAll(Player& player, Obstacle& obstacle1, Obstacle& obstacle2)
{
	srand(static_cast<unsigned int>(time(NULL)));

	const int screenWidth = 1080;
	const int screenHeight = 720;

	InitWindow(screenWidth, screenHeight, "Flappy Bird 0.1");

	InitPlayer(player);
	InitObstacle(obstacle1, 0.0f, 300);
	InitObstacle(obstacle2, static_cast<float>(GetScreenHeight() / 2 + player.height), GetScreenHeight());
	InitParallax();
}

void GameLoop()
{
	Screen screen = Screen::MENU;

	Player player;

	Obstacle obstacle1;
	Obstacle obstacle2;

	bool returnToMenu = false;

	InitAll(player, obstacle1, obstacle2);

	while (!WindowShouldClose())
	{
		SetExitKey(NULL);

		switch (screen)
		{
		case Screen::MENU:
			break;
		case Screen::GAME:
			UpdateParallax();
			Update(player, obstacle1, obstacle2, returnToMenu);
			break;
		case Screen::CREDITS:
			break;
		}

		BeginDrawing();
		ClearBackground(DARKGREEN);

		switch (screen)
		{
		case Screen::MENU:
			DrawMenu(screen);
			break;
		case Screen::GAME:
			DrawParallax();
#ifdef _DEBUG
			DrawObjectsHitboxes(player, obstacle1, obstacle2);
#endif
			DrawObstacles(obstacle1, obstacle2);
			GameDrawReturnButton(screen, returnToMenu);
			DrawPlayer(player);
			break;
		case Screen::CREDITS:
			DrawCredits();
			DrawReturnButton(screen, returnToMenu);
			break;
		}

		EndDrawing();
	}

	DeInitParallax();

	DeInitObstacle(obstacle1);
	DeInitObstacle(obstacle2);

	DeInitPlayer(player);

	CloseWindow();
}
}
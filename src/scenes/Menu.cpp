#include "Menu.h"

#include "raylib.h"

void DrawMenu(Screen& screen)
{
	DrawText("Flappy Bird", GetScreenWidth() / 2 - 250, GetScreenHeight() - 600, 100, WHITE);
	DrawText("Use the left button of the mosue to chosse an option", GetScreenWidth() - 750, GetScreenHeight() / 2 - 100, 20, WHITE);
	DrawText("Play", GetScreenWidth() / 2 - 40, GetScreenHeight() / 2, 30, RED);
	DrawText("Credits", GetScreenWidth() / 2 - 40, GetScreenHeight() / 2 + 120, 30, RED);
	
	if (GetMousePosition().x >= GetScreenWidth() / 2 - 40 && GetMousePosition().x <= GetScreenWidth() / 2 + 40
		&& GetMousePosition().y >= GetScreenHeight() / 2 && GetMousePosition().y <= GetScreenHeight() / 2 + 20)
	{
		DrawText("Play", GetScreenWidth() / 2 - 40, GetScreenHeight() / 2, 30, DARKBROWN);

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			screen = Screen::GAME;
		}
	}

	if (GetMousePosition().x >= GetScreenWidth() / 2 - 40 && GetMousePosition().x <= GetScreenWidth() / 2 + 80
		&& GetMousePosition().y >= GetScreenHeight() / 2 + 120 && GetMousePosition().y <= GetScreenHeight() / 2 + 140)
	{
		DrawText("Credits", GetScreenWidth() / 2 - 40, GetScreenHeight() / 2 + 120, 30, DARKBROWN);

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			screen = Screen::CREDITS;
		}
	}

	DrawText("0.2", GetScreenWidth() - 60, GetScreenHeight() - 40, 40, WHITE);
}

void DrawReturnButton(Screen& screen, bool& returnToMenu)
{
	int returnPosX = 40;
	int returnPosY = GetScreenHeight() - 50;

	DrawText("Return", returnPosX, returnPosY, 40, BLACK);

	if (GetMousePosition().x >= returnPosX && GetMousePosition().x <= returnPosX + 100
		&& GetMousePosition().y >= returnPosY && GetMousePosition().y <= returnPosY + 20)
	{
		DrawText("Return", returnPosX, returnPosY, 40, GRAY);

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			screen = Screen::MENU;
			returnToMenu = true;
		}
	}
}
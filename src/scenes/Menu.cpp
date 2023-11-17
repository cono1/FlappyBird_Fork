#include "Menu.h"

#include "raylib.h"

namespace game
{
static int optionsSize;

void DrawMenu(Screen& screen)
{
	int midScreenX = GetScreenWidth() / 2;
	int midScreenY = GetScreenHeight() / 2;
	optionsSize = 30;

	DrawText("Flappy Bird", midScreenX - 250, GetScreenHeight() - 600, 100, WHITE);
	DrawText("Left click to choose", midScreenX, midScreenY - 100, 20, WHITE);
	DrawText("Play", midScreenX - MeasureText("Play", optionsSize) / 2, midScreenY, optionsSize, RED);
	DrawText("Credits", midScreenX - MeasureText("Credits", optionsSize) / 2, midScreenY + static_cast<int>(MeasureTextEx(GetFontDefault(), "Play", static_cast<float>(optionsSize), 0).y), optionsSize, RED);

	if (GetMousePosition().x >= midScreenX - MeasureText("Play", optionsSize) / 2 &&
		GetMousePosition().x <= midScreenX + MeasureText("Play", optionsSize) / 2 &&
		GetMousePosition().y >= midScreenY && GetMousePosition().y <= midScreenY + optionsSize)
	{
		DrawText("Play", midScreenX - MeasureText("Play", optionsSize) / 2, GetScreenHeight() / 2, optionsSize, DARKBROWN);

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			screen = Screen::GAME;
		}
	}

	if (GetMousePosition().x >= midScreenX - MeasureText("Credits", optionsSize) / 2 &&
		GetMousePosition().x <= midScreenX + MeasureText("Credits", optionsSize) / 2 && 
		GetMousePosition().y >= midScreenY + static_cast<int>(MeasureTextEx(GetFontDefault(), "Play", static_cast<float>(optionsSize), 0).y) && GetMousePosition().y <= midScreenY + 140)
	{
		DrawText("Credits", midScreenX - MeasureText("Credits", optionsSize) / 2, midScreenY + static_cast<int>(MeasureTextEx(GetFontDefault(), "Play", static_cast<float>(optionsSize), 0).y), 30, DARKBROWN);

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

	if (GetMousePosition().x >= returnPosX && GetMousePosition().x <= returnPosX + 140
		&& GetMousePosition().y >= returnPosY && GetMousePosition().y <= returnPosY + 40)
	{
		DrawText("Return", returnPosX, returnPosY, 40, GRAY);

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			screen = Screen::MENU;
			returnToMenu = true;
		}
	}
}

void GameDrawReturnButton(Screen& screen, bool& returnToMenu)
{
	int returnPosX = GetScreenWidth() - 150;
	int returnPosY = GetScreenHeight() - 50;

	DrawText("Return", returnPosX, returnPosY, 40, BLACK);

	if (GetMousePosition().x >= returnPosX && GetMousePosition().x <= returnPosX + 140
		&& GetMousePosition().y >= returnPosY && GetMousePosition().y <= returnPosY + 40)
	{
		DrawText("Return", returnPosX, returnPosY, 40, GRAY);

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			screen = Screen::MENU;
			returnToMenu = true;
		}
	}
}
}
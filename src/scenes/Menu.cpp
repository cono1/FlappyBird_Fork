#include "Menu.h"

#include "raylib.h"

#include <string>

namespace game
{
static int optionsSize;

void DrawMenu(Screen& screen)
{
	std::string titleText = "Flappy Bird";
	std::string specText = "Left click to choose";
	std::string sPlayerText = "Singleplayer";
	std::string mPlayerText = "Multiplayer";
	std::string rulesText = "How to play";
	std::string creditsText = "Credits";

	int midScreenX = GetScreenWidth() / 2;
	int midScreenY = GetScreenHeight() / 2;

	Vector2 singlePlayerPos{ midScreenX - static_cast<float>(MeasureText(sPlayerText.c_str(), optionsSize)) / 2, static_cast<float>(midScreenY) };
	Vector2 multiPlayerPos{ midScreenX - static_cast<float>(MeasureText(mPlayerText.c_str(), optionsSize)) / 2, 
							midScreenY + MeasureTextEx(GetFontDefault(), sPlayerText.c_str(), static_cast<float>(optionsSize), 0).y };
	Vector2 rulesPos{ midScreenX - static_cast<float>(MeasureText(rulesText.c_str(), optionsSize)) / 2,
						midScreenY + MeasureTextEx(GetFontDefault(), rulesText.c_str(), static_cast<float>(optionsSize), 0).y * 2 };
	Vector2 creditsPos{ midScreenX - static_cast<float>(MeasureText(creditsText.c_str(), optionsSize)) / 2,
						midScreenY + MeasureTextEx(GetFontDefault(), sPlayerText.c_str(), static_cast<float>(optionsSize), 0).y * 3 };


	int titleSize = 100; 
	int otherTextsize = 20;
	optionsSize = 30;

	DrawText(titleText.c_str(), midScreenX - 250, GetScreenHeight() - 600, titleSize, WHITE);
	DrawText(specText.c_str(), midScreenX, midScreenY - 100, otherTextsize, WHITE);
	DrawText(sPlayerText.c_str(), static_cast<int>(singlePlayerPos.x), static_cast<int>(singlePlayerPos.y), optionsSize, RED);
	DrawText(mPlayerText.c_str(), static_cast<int>(multiPlayerPos.x), static_cast<int>(multiPlayerPos.y), optionsSize, RED);
	DrawText(rulesText.c_str(), static_cast<int>(rulesPos.x), static_cast<int>(rulesPos.y), optionsSize, RED);
	DrawText(creditsText.c_str(), static_cast<int>(creditsPos.x), static_cast<int>(creditsPos.y), optionsSize, RED);

	if (GetMousePosition().x >= singlePlayerPos.x &&
		GetMousePosition().x <= singlePlayerPos.x + MeasureText(sPlayerText.c_str(), optionsSize) &&
		GetMousePosition().y >= singlePlayerPos.y && 
		GetMousePosition().y <= singlePlayerPos.y + MeasureTextEx(GetFontDefault(), sPlayerText.c_str(), static_cast<float>(optionsSize), 0).y)
	{
		DrawText(sPlayerText.c_str(), static_cast<int>(singlePlayerPos.x), static_cast<int>(singlePlayerPos.y), optionsSize, DARKBROWN);

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			screen = Screen::SINGLEPLAYER;
		}
	}

	if (GetMousePosition().x >= multiPlayerPos.x &&
		GetMousePosition().x <= multiPlayerPos.x + MeasureText(mPlayerText.c_str(), optionsSize) &&
		GetMousePosition().y >= multiPlayerPos.y &&
		GetMousePosition().y <= multiPlayerPos.y + MeasureTextEx(GetFontDefault(), mPlayerText.c_str(), static_cast<float>(optionsSize), 0).y)
	{
		DrawText(mPlayerText.c_str(), static_cast<int>(multiPlayerPos.x), static_cast<int>(multiPlayerPos.y), optionsSize, DARKBROWN);

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			screen = Screen::MULTIPLAYER;
		}
	}

	if (GetMousePosition().x >= rulesPos.x &&
		GetMousePosition().x <= rulesPos.x + MeasureText(rulesText.c_str(), optionsSize) &&
		GetMousePosition().y >= rulesPos.y &&
		GetMousePosition().y <= rulesPos.y + MeasureTextEx(GetFontDefault(), rulesText.c_str(), static_cast<float>(optionsSize), 0).y)
	{
		DrawText(rulesText.c_str(), static_cast<int>(rulesPos.x), static_cast<int>(rulesPos.y), optionsSize, DARKBROWN);

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			screen = Screen::RULES;
		}
	}

	if (GetMousePosition().x >= creditsPos.x &&
		GetMousePosition().x <= creditsPos.x + MeasureText(creditsText.c_str(), optionsSize) &&
		GetMousePosition().y >= creditsPos.y &&
		GetMousePosition().y <= creditsPos.y + MeasureTextEx(GetFontDefault(), creditsText.c_str(), static_cast<float>(optionsSize), 0).y)
	{
		DrawText(creditsText.c_str(), static_cast<int>(creditsPos.x), static_cast<int>(creditsPos.y), optionsSize, DARKBROWN);

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			screen = Screen::CREDITS;
		}
	}

	DrawText("0.3", GetScreenWidth() - 60, GetScreenHeight() - 40, 40, WHITE);
}

void DrawReturnButton(Screen& screen, bool& returnToMenu)
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

void DrawPauseButton(Screen& screen)
{
	int pausePosX = GetScreenWidth() - 150;
	int pausePosY = GetScreenHeight() - 50;

	int pauseSize = 40;

	DrawText("Pause", pausePosX, pausePosY, pauseSize, BLACK);

	if (GetMousePosition().x >= pausePosX && GetMousePosition().x <= pausePosX + 140
		&& GetMousePosition().y >= pausePosY && GetMousePosition().y <= pausePosY + 40)
	{
		DrawText("Pause", pausePosX, pausePosY, pauseSize, GRAY);

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			screen = Screen::PAUSE;
		}
	}
}
}
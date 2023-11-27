#include "Pause.h"

#include <string>

#include "raylib.h"

namespace game
{
void DrawPauseScreen(Screen& screen, Screen previousScreen, bool& returnToMenu)
{
	int optionsSize = 40;
	int pauseSize = 65;

	std::string pauseText = "PAUSED";
	std::string playText = "Play";
	std::string menuText = "Menu";

	Vector2 pauseTextPos = { GetScreenWidth() / 2 - static_cast<float>(MeasureText(pauseText.c_str(), pauseSize)) / 2, static_cast<float>(GetScreenHeight()) / 3 };
	Vector2 playTextPos = { GetScreenWidth() / 2 - static_cast<float>(MeasureText(playText.c_str(), optionsSize)) / 2, pauseTextPos.y + 100 };
	Vector2 menuTextPos = { GetScreenWidth() / 2 - static_cast<float>(MeasureText(menuText.c_str(), optionsSize)) / 2, playTextPos.y + 80 };

	DrawText(pauseText.c_str(), static_cast<int>(pauseTextPos.x), static_cast<int>(pauseTextPos.y), pauseSize, WHITE);
	DrawText(playText.c_str(), static_cast<int>(playTextPos.x), static_cast<int>(playTextPos.y), optionsSize, WHITE);
	DrawText(menuText.c_str(), static_cast<int>(menuTextPos.x), static_cast<int>(menuTextPos.y), optionsSize, WHITE);


	if (GetMousePosition().x >= playTextPos.x &&
		GetMousePosition().x <= playTextPos.x + MeasureText(playText.c_str(), pauseSize) &&
		GetMousePosition().y >= playTextPos.y &&
		GetMousePosition().y <= playTextPos.y + MeasureTextEx(GetFontDefault(), playText.c_str(), static_cast<float>(optionsSize), 0).y)
	{
		DrawText(playText.c_str(), static_cast<int>(playTextPos.x), static_cast<int>(playTextPos.y), optionsSize, DARKBROWN);

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			if (previousScreen == Screen::SINGLEPLAYER) screen = Screen::SINGLEPLAYER;

			if (previousScreen == Screen::MULTIPLAYER) screen = Screen::MULTIPLAYER;
		}
	}

	if (GetMousePosition().x >= menuTextPos.x &&
		GetMousePosition().x <= menuTextPos.x + MeasureText(menuText.c_str(), optionsSize) &&
		GetMousePosition().y >= menuTextPos.y &&
		GetMousePosition().y <= menuTextPos.y + MeasureTextEx(GetFontDefault(), menuText.c_str(), static_cast<float>(optionsSize), 0).y)
	{
		DrawText(menuText.c_str(), static_cast<int>(menuTextPos.x), static_cast<int>(menuTextPos.y), optionsSize, DARKBROWN);

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			screen = Screen::MENU;
			returnToMenu = true;
		}
	}
}
}
#pragma once

namespace game
{
enum class Screen
{
	MENU,
	SINGLEPLAYER,
	MULTIPLAYER,
	CREDITS
};

// dibuja el men�
void DrawMenu(Screen& screen);

// bot�n que vuelve al men�
void DrawReturnButton(Screen& screen, bool& returnToMenu);

void GameDrawReturnButton(Screen& screen, bool& returnToMenu);
}
#pragma once

namespace game
{
enum class Screen
{
	MENU,
	SINGLEPLAYER,
	MULTIPLAYER,
	RULES,
	CREDITS
};

// dibuja el men�
void DrawMenu(Screen& screen);

// bot�n que vuelve al men�
void GameDrawReturnButton(Screen& screen, bool& returnToMenu);
}
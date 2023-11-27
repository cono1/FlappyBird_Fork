#pragma once

namespace game
{
enum class Screen
{
	MENU,
	SINGLEPLAYER,
	MULTIPLAYER,
	RULES,
	CREDITS,
	PAUSE,
	LOOSESCREEN,
	WINSCREEN
};

// dibuja el men�
void DrawMenu(Screen& screen);

// bot�n que vuelve al men�
void DrawReturnButton(Screen& screen, bool& returnToMenu);

void DrawPauseButton(Screen& screen);
}
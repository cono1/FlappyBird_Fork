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
	ENDSCREEN
};

// dibuja el menú
void DrawMenu(Screen& screen);

// botón que vuelve al menú
void DrawReturnButton(Screen& screen, bool& returnToMenu);

void DrawPauseButton(Screen& screen);
}
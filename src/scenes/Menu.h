#pragma once

enum class Screen
{
	MENU,
	GAME,
	CREDITS
};

// dibuja el menú
void DrawMenu(Screen& screen);

// botón que vuelve al menú
void DrawReturnButton(Screen& screen, bool& returnToMenu);
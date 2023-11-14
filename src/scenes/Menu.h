#pragma once

enum class Screen
{
	MENU,
	GAME,
	CREDITS
};

// dibuja el menú
void DrawMenu(Screen& screen);
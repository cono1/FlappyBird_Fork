#include "WinScreen.h"

#include <string>

#include "raylib.h"

#include "objects/Score.h"

namespace game
{
bool CheckButtonPressed(const Vector2& buttonPos, const std::string& buttonText, int textSize);

void DrawWinScreen(Screen& screen, Screen previousScreen)
{
    int halfScreenX = GetScreenWidth() / 2;
    int optionsSize = 40;
    int titleSize = 80;
    Color titleColor = WHITE;
    Color optionsColor = LIGHTGRAY;

    std::string winText = "YOU WIN!";
    std::string playAgainText = "Play Again";
    std::string menuText = "Main Menu";

    Vector2 winTextPos = { halfScreenX - static_cast<float>(MeasureText(winText.c_str(), titleSize)) / 2, static_cast<float>(GetScreenHeight()) / 3 };
    Vector2 playAgainTextPos = { halfScreenX - static_cast<float>(MeasureText(playAgainText.c_str(), optionsSize)) / 2, winTextPos.y + 150 };
    Vector2 menuTextPos = { halfScreenX - static_cast<float>(MeasureText(menuText.c_str(), optionsSize)) / 2, playAgainTextPos.y + 80 };

    DrawText(winText.c_str(), static_cast<int>(winTextPos.x), static_cast<int>(winTextPos.y), titleSize, titleColor);
    DrawText(playAgainText.c_str(), static_cast<int>(playAgainTextPos.x), static_cast<int>(playAgainTextPos.y), optionsSize, optionsColor);
    DrawText(menuText.c_str(), static_cast<int>(menuTextPos.x), static_cast<int>(menuTextPos.y), optionsSize, optionsColor);

    if (CheckButtonPressed(playAgainTextPos, playAgainText, optionsSize))
    {
        if (previousScreen == Screen::SINGLEPLAYER)screen = Screen::SINGLEPLAYER;

        if (previousScreen == Screen::MULTIPLAYER) screen = Screen::MULTIPLAYER;

        ResetScore();
    }

    if (CheckButtonPressed(menuTextPos, menuText, optionsSize))
    {
        screen = Screen::MENU;
        ResetScore();
    }
}

bool CheckButtonPressed(const Vector2& buttonPos, const std::string& buttonText, int textSize)
{
    if (GetMousePosition().x >= buttonPos.x &&
        GetMousePosition().x <= buttonPos.x + MeasureText(buttonText.c_str(), textSize) &&
        GetMousePosition().y >= buttonPos.y &&
        GetMousePosition().y <= buttonPos.y + MeasureTextEx(GetFontDefault(), buttonText.c_str(), static_cast<float>(textSize), 0).y)
    {
        DrawText(buttonText.c_str(), static_cast<int>(buttonPos.x), static_cast<int>(buttonPos.y), textSize, DARKBROWN);

        return (IsMouseButtonPressed(MOUSE_BUTTON_LEFT));
    }

    return false;
}
}
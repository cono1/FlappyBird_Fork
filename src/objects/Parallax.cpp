#include "Parallax.h"

#include "raylib.h"

namespace game
{
static Texture2D foreground;
static Texture2D background;

static float scrollingFore;
static float scrollingBack;

void InitParallax()
{
	foreground = LoadTexture("res/assets/background/forestBack.png");
	background = LoadTexture("res/assets/background/forestFore.png");
	scrollingFore = 0.0f;
	scrollingBack = 0.0f;
}
	
void UpdateParallax()
{
	scrollingFore -= 100.0f * GetFrameTime();
	scrollingBack -= 50.0f * GetFrameTime();

	if (scrollingFore <= -foreground.width * 2) scrollingFore = 0;
	if (scrollingBack <= -background.width * 2) scrollingBack = 0;
}
	
void DrawParallax()
{
	DrawTextureEx(background, Vector2{ scrollingBack, 20 }, 0.0f, 2.0f, WHITE);
	DrawTextureEx(background, Vector2{ background.width * 2 + scrollingBack, 20 }, 0.0f, 2.0f, WHITE);

	DrawTextureEx(foreground, Vector2{ scrollingFore, 0 }, 0.0f, 2.0f, WHITE);
	DrawTextureEx(foreground, Vector2{ foreground.width * 2 + scrollingFore, 0 }, 0.0f, 2.0f, WHITE);
}

void DeInitParallax()
{
	UnloadTexture(foreground);
	UnloadTexture(background);
}
}
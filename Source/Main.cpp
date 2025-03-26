#include "raylib.h"
#include "Button.h"
#include "SelectGame.h"
#include "SnakeGame/Setting.h"
#include "SnakeGame/Food.h"
#include "SnakeGame/SnakeLoop.h"

int main() {
	InitWindow(450, 700, "Sue's Game Creation");
	SetTargetFPS(60);

	Texture2D background = LoadTexture("Graphics/background.png");
	Button startBtn{ "Graphics/startBtn.png", {200, 300}, 1.0 };
	Button closeBtn{ "Graphics/closeBtn.png", {200, 500}, 1.0 };
	
	bool exit = false;

	while (!WindowShouldClose() && exit == false) {
		Vector2 mousePos = GetMousePosition();
		bool mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

		if (startBtn.isPressed(mousePos, mousePressed)) {
			SelectGame select;
			select.run();
		}

		if (closeBtn.isPressed(mousePos, mousePressed)) {
			exit = true;
		}

		BeginDrawing();
		ClearBackground(BLACK);
		DrawTexture(background, 0, 0, WHITE);
		startBtn.Draw();
		closeBtn.Draw();
		EndDrawing();
	}
	CloseWindow();
}
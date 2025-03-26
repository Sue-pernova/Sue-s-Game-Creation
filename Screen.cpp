#include "raylib.h"
#include "Screen.h"
#include "Tetris/TetrisLoop.h"
#include "SnakeGame/SnakeLoop.h"
#include "SnakeGame/Setting.h"
#include <ctime>
#include <cstdlib>

// Title
TitleScreen::TitleScreen() : startbtn("Graphics/startBtn.png", "Graphics/startBtn2.png", "Sounds/tap.mp3", { 100, 520 }, 1.0f) {
	background = LoadTexture("Graphics/background.png");
}
TitleScreen::~TitleScreen() {
	UnloadTexture(background);
}

void TitleScreen::Update() {
	SetWindowSize(450, 700);
	SetWindowTitle("SSue's Game Creation");

	Vector2 mousePos = GetMousePosition();
	startbtn.Update(mousePos);

	if (startbtn.isPressed(mousePos, IsMouseButtonPressed(MOUSE_LEFT_BUTTON))) {
		currentWindow = SELECT;
	}
}
void TitleScreen::Draw() {
	DrawTexture(background, 0, 0, WHITE);
	startbtn.Draw();
}


// SelectGame
SelectScreen::SelectScreen()
	:snakebtn("Graphics/snakeBtn.png", "Graphics/snakeBtn2.png", "Sounds/tap.mp3", { 50, 260 }, 1.0f),
		tetrisbtn("Graphics/tetrisBtn.png", "Graphics/tetrisBtn2.png", "Sounds/tap.mp3", { 60, 560 }, 1.0f)
{
	background = LoadTexture("Graphics/background2.png");
}
SelectScreen::~SelectScreen() {
	UnloadTexture(background);
}

void SelectScreen::Update() {
	SetWindowSize(450, 700);
	SetWindowTitle("SSue's Game Creation / Select Game");
	Vector2 mousePos = GetMousePosition();
	snakebtn.Update(mousePos);
	tetrisbtn.Update(mousePos);

	if (snakebtn.isPressed(mousePos, IsMouseButtonPressed(MOUSE_LEFT_BUTTON))) {
		currentWindow = SNAKE;
	}
	if (tetrisbtn.isPressed(mousePos, IsMouseButtonPressed(MOUSE_LEFT_BUTTON))) {
		currentWindow = TETRIS;
	}

}
void SelectScreen::Draw() {
	DrawTexture(background, 0, 0, WHITE);
	snakebtn.Draw();
	tetrisbtn.Draw();
}


// SnakeGame
void SnakeScreen::Update() {
	SetWindowSize(offset * 2 + canvasSize, offset * 2 + canvasSize);
	SetWindowTitle("SSue's Game Creation / Snake Game");
}
void SnakeScreen::Draw() {
	SnakeLoop s(currentBgm);
	s.run();
}


// Tetris

void TetrisScreen::Update() {
	SetWindowSize(500, 620);
	SetWindowTitle("SSue's Game Creation / Tetris");
	if (IsKeyPressed(KEY_A)) {
		currentWindow = ENDING;
	}
}
void TetrisScreen::Draw() {
	srand(time(NULL));
	TetrisLoop t(currentBgm);
	t.Run();
}


// Ending
EndingScreen::EndingScreen()
	:ending("Graphics/closeBtn.png", "Graphics/closeBtn2.png", "Sounds/tap.mp3", { 220, 230 }, 1.0f) {
	background = LoadTexture("Graphics/ending.png");
}
EndingScreen::~EndingScreen() {
	UnloadTexture(background);
}
void EndingScreen::Update() {
	SetWindowSize(700, 700);

	Vector2 mousePos = GetMousePosition();
	ending.Update(mousePos);

	if (ending.isPressed(mousePos, IsMouseButtonPressed(MOUSE_LEFT_BUTTON))) {
		currentWindow = TITLE;
	}
	
}
void EndingScreen::Draw() {
	DrawTexture(background, 0, 0, WHITE);
	ending.Draw();
}

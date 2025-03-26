#include <iostream>
#include "raylib.h"
#include "Screen.h"

Window currentWindow = TITLE;
const char* currentMusicPath = "Sounds/Pajama Party - Jeremy Korpas.mp3";

void changeBGM(Music& currentMusic, const char* newMusicPath) {
	// ���ο� ���� ���� ��ΰ� ���� ���ǰ� ���ٸ� �������� ����
	if (strcmp(newMusicPath, currentMusicPath) != 0) {
		// ���� ������ ��� ���̸� ����
		if (IsMusicStreamPlaying(currentMusic)) {
			StopMusicStream(currentMusic);
		}

		// ���ο� ���� �ε�
		currentMusic = LoadMusicStream(newMusicPath);

		// ���ο� ���� ���
		PlayMusicStream(currentMusic);

		// ���� ��� ������Ʈ
		currentMusicPath = newMusicPath;
	}
}

int main() {
	InitWindow(450, 700, "SSue's Game Creation");
	SetTargetFPS(60);

	InitAudioDevice();

	Music currentBgm = LoadMusicStream("Sounds/Pajama Party - Jeremy Korpas.mp3");
	PlayMusicStream(currentBgm);

	float timePlayed = 0.0f;        // Time played normalized [0.0f..1.0f]
	bool pause = false;


	// ȭ�� Ŭ���� ��ü �ҷ�����
	TitleScreen w1;
	SelectScreen w2;
	SnakeScreen w3(currentBgm);
	TetrisScreen w4(currentBgm);
	EndingScreen w5;

	// â �׸��� ����
	while (!WindowShouldClose()) {
		UpdateMusicStream(currentBgm);
		timePlayed = GetMusicTimePlayed(currentBgm) / GetMusicTimeLength(currentBgm);

		if (timePlayed > 1.0f) timePlayed = 1.0f;


		Vector2 mousePos = GetMousePosition();
		bool mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

		// ȭ�� �׸���
		BeginDrawing();
		ClearBackground(RAYWHITE);
		switch (currentWindow) {
		case TITLE:
			changeBGM(currentBgm, "Sounds/Pajama Party - Jeremy Korpas.mp3");
			w1.Update();
			w1.Draw();
			break;
		case SELECT:
			changeBGM(currentBgm, "Sounds/Pajama Party - Jeremy Korpas.mp3");
			w2.Update();
			w2.Draw();
			break;
		case SNAKE:
			changeBGM(currentBgm, "Sounds/Best Game Console-DJARTMUSIC.mp3");
			w3.Update();
			w3.Draw();
			break;
		case TETRIS:
			changeBGM(currentBgm, "Sounds/tetris_music.mp3");
			w4.Update();
			w4.Draw();
			break;
		case ENDING:
			changeBGM(currentBgm, "Sounds/Kitty Down the Stairs - Joel Cummins.mp3");
			w5.Update();
			w5.Draw();
			break;
		}
		EndDrawing();
	}

	UnloadMusicStream(currentBgm);
	CloseAudioDevice();
	CloseWindow();

	return 0;
}
#include <iostream>
#include "raylib.h"
#include "Screen.h"

Window currentWindow = TITLE;
const char* currentMusicPath = "Sounds/Pajama Party - Jeremy Korpas.mp3";

void changeBGM(Music& currentMusic, const char* newMusicPath) {
	// 새로운 음악 파일 경로가 현재 음악과 같다면 변경하지 않음
	if (strcmp(newMusicPath, currentMusicPath) != 0) {
		// 현재 음악이 재생 중이면 멈춤
		if (IsMusicStreamPlaying(currentMusic)) {
			StopMusicStream(currentMusic);
		}

		// 새로운 음악 로드
		currentMusic = LoadMusicStream(newMusicPath);

		// 새로운 음악 재생
		PlayMusicStream(currentMusic);

		// 음악 경로 업데이트
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


	// 화면 클래스 객체 불러오기
	TitleScreen w1;
	SelectScreen w2;
	SnakeScreen w3(currentBgm);
	TetrisScreen w4(currentBgm);
	EndingScreen w5;

	// 창 그리기 루프
	while (!WindowShouldClose()) {
		UpdateMusicStream(currentBgm);
		timePlayed = GetMusicTimePlayed(currentBgm) / GetMusicTimeLength(currentBgm);

		if (timePlayed > 1.0f) timePlayed = 1.0f;


		Vector2 mousePos = GetMousePosition();
		bool mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

		// 화면 그리기
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
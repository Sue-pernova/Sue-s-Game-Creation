<<<<<<< HEAD
﻿#include <raylib.h>
#include "game.h"
#include "colors.h"
#include <iostream>

using namespace std;

double lastUpdateTime = 0;

// 블럭이 일정 시간 간격으로 낙하 하도록 구현
bool EventTriggered(double interval) // 이전 업데이트 시간을 저장하는 변수 //일정 시간 간격으로 블록을 떨어뜨리기 위해서 사용
{
	double currentTime = GetTime(); // 현재 시간(초 단위)
	if(currentTime - lastUpdateTime >= interval)
	{
		lastUpdateTime = currentTime; // 마지막 업데이트 시간 갱신하기
		return true; // true일 경우 이벤트 트리거 발생!
	}
	return false;
}

int main() // 게임 루프
{
    InitWindow(500, 620, "SSUE's Tetris");
    SetTargetFPS(60); // 프레임 값을 60으로 설정

    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);

    Game game = Game();

    while (WindowShouldClose() == false)
    {
        UpdateMusicStream(game.music);
        game.HandleInput(); 
       
        if (EventTriggered(0.8)) // 낙하 속도 조절 
        {
            game.MoveBlockDown(); // 0.8초마다 떨어지도록
        }

        BeginDrawing(); // 화면 그리기 시작
        ClearBackground(darkBlue); // 배경생은 darkBlue
        DrawTextEx(font, "Score", { 360, 15 }, 30, 2, WHITE); // 점수 판 생성
        DrawTextEx(font, "Next", { 370, 175 }, 30, 2, WHITE); // 다음 나올 블럭 모양 이미지
       
        if (game.gameOver) // 게임이 종료되면 GAME OVER 출력 하도록
        {
            DrawTextEx(font, "GAME OVER", { 320, 450 }, 30, 2, WHITE); // 게임 오버 메시지
        }
        DrawRectangleRounded({ 320, 55, 170, 60 }, 0.3, 6, lightBlue);

        char scoreText[10];
        sprintf_s(scoreText, sizeof(scoreText), "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2); // MeasureTextEx(): 글자 크기 측정후 가운데 정렬

        DrawTextEx(font, scoreText, { 320 + (170 - textSize.x) / 2, 65 }, 38, 2, WHITE);
        DrawRectangleRounded({ 320, 215, 170, 180 }, 0.3, 6, lightBlue);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
=======
﻿#include "TetrisLoop.h"
#include <ctime>
#include <cstdlib>

int main() {
    srand(time(NULL));
    TetrisLoop loop;
    loop.Run();
    return 0;
>>>>>>> 4c45677 (make Loop file)
}
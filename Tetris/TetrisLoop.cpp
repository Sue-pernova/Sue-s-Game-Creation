#include "TetrisLoop.h"
#include "colors.h"
#include "../Screen.h"
#include <iostream>
#include <cstdlib>   // rand, srand
#include <ctime>     // time

// 생성자
TetrisLoop::TetrisLoop(Music& bgm) : lastUpdateTime(0)
{
    srand(time(NULL));
    currentBgm = bgm;

    // 폰트 불러오기
    font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);
}

TetrisLoop::~TetrisLoop()
{
    // 불러온 폰트 메모리 해제
    UnloadFont(font);
}

bool TetrisLoop::EventTriggered(double interval)
{
    double currentTime = GetTime(); // 현재 시간(초 단위)
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true; // (interval 초가 지나면 true 반환)
    }
    return false;
}

// 게임 루프 실행
void TetrisLoop::Run()
{
    while (WindowShouldClose() == false)
    {
        UpdateMusicStream(currentBgm);

        game.HandleInput();


        if (EventTriggered(0.8))
        {
            game.MoveBlockDown();
        }

        BeginDrawing();
        ClearBackground(lightPink);

        DrawTextEx(font, "Score", { 360, 15 }, 30, 2, BLACK);

        DrawTextEx(font, "Next", { 370, 175 }, 30, 2, BLACK);

        if (game.gameOver)
        {
            currentWindow = ENDING;
            break;
        }

        DrawRectangleRounded({ 320, 55, 170, 60 }, 0.3, 6, WHITE);

        // 점수
        char scoreText[10];
        sprintf_s(scoreText, sizeof(scoreText), "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);
        DrawTextEx(font, scoreText, { 310 + (170 - textSize.x) / 2, 65 }, 38, 2, BLACK);
        DrawRectangleRounded({ 320, 215, 170, 180 }, 0.3, 6, WHITE);

        game.Draw();

        EndDrawing();
    }
}
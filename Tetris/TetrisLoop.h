#ifndef TETRIS_LOOP_H
#define TETRIS_LOOP_H
// ifndef, define, endif: 해당 헤더 파일이 두 번 이상 포함되는 것을 방지하는 매크로
// 중복 포함 오류를 막기위함

#include <raylib.h>
#include "game.h"

class TetrisLoop
{
public:
    // 생성자
    TetrisLoop();

    // 소멸자
    ~TetrisLoop();
    void Run();

private:
    // 블럭 자동 낙하
    bool EventTriggered(double interval);

    // 게임 로직
    Game game;

    Font font;

    double lastUpdateTime;
};

#endif
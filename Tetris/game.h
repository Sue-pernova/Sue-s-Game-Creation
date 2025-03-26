<<<<<<< HEAD
#pragma once
=======
﻿#pragma once
>>>>>>> 4c45677 (make Loop file)
#include "grid.h"
#include "blocks.cpp"

using namespace std;

class Game
{
public:
<<<<<<< HEAD
    Game();
=======
    // 생성자
    Game();

    // 소멸자(게임이 끝날 때 호출)
>>>>>>> 4c45677 (make Loop file)
    ~Game();
    void Draw();
    void HandleInput();
    void MoveBlockDown();
    bool gameOver;
    int score;
    Music music;

private:
    void MoveBlockLeft();
    void MoveBlockRight();
    Block GetRandomBlock();
    vector<Block> GetAllBlocks();
<<<<<<< HEAD
    bool IsBlockOutside();
=======
    bool IsBlockOutside(); // 현재 블록이 브리드 밖으로 나갔는지 검사
>>>>>>> 4c45677 (make Loop file)
    void RotateBlock();
    void LockBlock();
    bool BlockFits();
    void Reset();
    void UpdateScore(int linesCleared, int moveDownPoints);
    Grid grid;
    vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
<<<<<<< HEAD
    Sound rotateSound;
    Sound clearSound;
=======
    Sound rotateSound; // 회전시 효과음
    Sound clearSound; // 줄 삭제시 효과음
>>>>>>> 4c45677 (make Loop file)
};
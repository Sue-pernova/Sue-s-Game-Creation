#include "block.h"

using namespace std;

<<<<<<< HEAD
=======
// 생성자
>>>>>>> 4c45677 (make Loop file)
Block::Block()
{
    cellSize = 30;
    rotationState = 0;
    colors = GetCellColors();
    rowOffset = 0;
    columnOffset = 0;
}

void Block::Draw(int offsetX,int offsetY)
{
<<<<<<< HEAD
    vector<Position> tiles = GetCellPositions();
=======
    vector<Position> tiles = GetCellPositions(); // 현재 블록의 셀 위치를 가져옴
>>>>>>> 4c45677 (make Loop file)
    for (Position item : tiles)
    {
        DrawRectangle(item.column * cellSize + offsetX, item.row * cellSize + offsetY, cellSize - 1, cellSize - 1, colors[id]);
    }
}

<<<<<<< HEAD
=======
// 행,열 방향으로 이동
>>>>>>> 4c45677 (make Loop file)
void Block::Move(int rows, int columns)
{
    rowOffset += rows;
    columnOffset += columns;
}

<<<<<<< HEAD
=======
// 현재 블록 모양 가져오기 // 충동 체크시에도 검사
>>>>>>> 4c45677 (make Loop file)
vector<Position> Block::GetCellPositions()
{
    vector<Position> tiles = cells[rotationState];
    vector<Position> movedTiles;
    for (Position item : tiles)
    {
        Position newPos = Position(item.row + rowOffset, item.column + columnOffset);
        movedTiles.push_back(newPos);
    }
    return movedTiles;
}

<<<<<<< HEAD
=======
// 시계방향으로 회전
>>>>>>> 4c45677 (make Loop file)
void Block::Rotate()
{
    rotationState++;
    if (rotationState == (int)cells.size())
    {
        rotationState = 0;
    }
}

<<<<<<< HEAD
=======
// 회전 복원
>>>>>>> 4c45677 (make Loop file)
void Block::UndoRotation()
{
    rotationState--;
    if (rotationState == -1)
    {
        rotationState = cells.size() - 1;
    }
}
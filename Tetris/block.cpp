#include "block.h"

using namespace std;

<<<<<<< HEAD
=======
// ������
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
    vector<Position> tiles = GetCellPositions(); // ���� ����� �� ��ġ�� ������
>>>>>>> 4c45677 (make Loop file)
    for (Position item : tiles)
    {
        DrawRectangle(item.column * cellSize + offsetX, item.row * cellSize + offsetY, cellSize - 1, cellSize - 1, colors[id]);
    }
}

<<<<<<< HEAD
=======
// ��,�� �������� �̵�
>>>>>>> 4c45677 (make Loop file)
void Block::Move(int rows, int columns)
{
    rowOffset += rows;
    columnOffset += columns;
}

<<<<<<< HEAD
=======
// ���� ��� ��� �������� // �浿 üũ�ÿ��� �˻�
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
// �ð�������� ȸ��
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
// ȸ�� ����
>>>>>>> 4c45677 (make Loop file)
void Block::UndoRotation()
{
    rotationState--;
    if (rotationState == -1)
    {
        rotationState = cells.size() - 1;
    }
}
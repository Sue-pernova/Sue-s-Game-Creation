#include <iostream>
#include "grid.h"
#include "colors.h"

using namespace std;

// Grid 생성자 초기화
Grid::Grid()
{
    numRows = 20;
    numCols = 10;
    cellSize = 30;
    Initialize();
    colors = GetCellColors(); // color 벡터 초기화 // 중요!!
}

// 격자 초기화
void Grid::Initialize()
{
    for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column < numCols; column++)
        {
            grid[row][column] = 0; // 0으로 초기화하여 Print 실행시 0 0 0 (..) 으로 출력 되도록
        }
    }
}

// 격자 상태 출력
void Grid::Print()
{
    for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column < numCols; column++)
        {
            cout << grid[row][column] << " ";
        }

        cout << endl;

    }
}

// 격자를 화면에 나타내기
void Grid::Draw()
{
    for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column < numCols; column++)
        {
            int cellValue = grid[row][column];
            DrawRectangle(column * cellSize + 11, row * cellSize + 11, cellSize - 1, cellSize - 1, colors[cellValue]); // colors[cellValue]
        }
    }
}

bool Grid::IsCellOutside(int row, int column)
{
    if (row >= 0 && row < numRows && column >= 0 && column < numCols)
    {
        return false;
    }
    return true; // 블럭이 마지막 줄에 걸리도록 // true가 아닌 false일 경우 계속 아래로 내려가 창을 벗어나 사라짐  
}

bool Grid::IsCellEmpty(int row, int column)
{
    if (grid[row][column] == 0)
    {
        return true;
    }
    return false;
}

int Grid::ClearFullRows()
{
    int completed = 0;
    for (int row = numRows - 1; row >= 0; row--)
    {
        if (IsRowFull(row))
        {
            ClearRow(row);
            completed++;
        }
        else if (completed > 0)
        {
            MoveRowDown(row, completed);
        }
    }
    return completed;
}

bool Grid::IsRowFull(int row)
{
    for (int column = 0; column < numCols; column++)
    {
        if (grid[row][column] == 0)
        {
            return false;
        }
    }
    return true;
}

void Grid::ClearRow(int row)
{
    for (int column = 0; column < numCols; column++)
    {
        grid[row][column] = 0;
    }
}

void Grid::MoveRowDown(int row, int numRows)
{
    for (int column = 0; column < numCols; column++)
    {
        grid[row + numRows][column] = grid[row][column];
        grid[row][column] = 0;
    }
}
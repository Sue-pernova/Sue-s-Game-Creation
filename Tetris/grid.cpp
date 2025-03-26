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
<<<<<<< HEAD
        cout << std::endl;
=======
        cout << endl;
>>>>>>> 4c45677 (make Loop file)
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
            DrawRectangle(column * cellSize + 11, row * cellSize + 11, cellSize - 1, cellSize - 1, colors[cellValue]);
        }
    }
}

<<<<<<< HEAD
=======
// 셀이 격자를 벗어나는지 검사
>>>>>>> 4c45677 (make Loop file)
bool Grid::IsCellOutside(int row, int column)
{
    if (row >= 0 && row < numRows && column >= 0 && column < numCols)
    {
<<<<<<< HEAD
        return false;
=======
        return false; // 정상 위치면 false 반환
>>>>>>> 4c45677 (make Loop file)
    }
    return true; // 블럭이 마지막 줄에 걸리도록 // true가 아닌 false일 경우 계속 아래로 내려가 창을 벗어나 사라짐  
}

<<<<<<< HEAD
=======
// 충돌 검사, 블록 이동 가능 여부를 판단해주는 함수
>>>>>>> 4c45677 (make Loop file)
bool Grid::IsCellEmpty(int row, int column)
{
    if (grid[row][column] == 0)
    {
        return true;
    }
    return false;
}

<<<<<<< HEAD
=======
// 줄 삭제
>>>>>>> 4c45677 (make Loop file)
int Grid::ClearFullRows()
{
    int completed = 0;
    for (int row = numRows - 1; row >= 0; row--)
    {
        if (IsRowFull(row))
        {
<<<<<<< HEAD
            ClearRow(row);
=======
            ClearRow(row); // 채워진 줄 삭제
>>>>>>> 4c45677 (make Loop file)
            completed++;
        }
        else if (completed > 0)
        {
<<<<<<< HEAD
            MoveRowDown(row, completed);
        }
    }
    return completed;
}

=======
            MoveRowDown(row, completed); // 삭제된 줄 위의 블럭 아래로 떨어뜨리기
        }
    }
    return completed; // 삭제한 줄 수 반환 -> 점수계산 하기
}

// 줄이 가득 채워졌는지 확인
>>>>>>> 4c45677 (make Loop file)
bool Grid::IsRowFull(int row)
{
    for (int column = 0; column < numCols; column++)
    {
        if (grid[row][column] == 0)
        {
<<<<<<< HEAD
            return false;
=======
            return false; // 비어있으면 false 반환
>>>>>>> 4c45677 (make Loop file)
        }
    }
    return true;
}

<<<<<<< HEAD
=======
// 줄 지우기
>>>>>>> 4c45677 (make Loop file)
void Grid::ClearRow(int row)
{
    for (int column = 0; column < numCols; column++)
    {
        grid[row][column] = 0;
    }
}

<<<<<<< HEAD
=======
// 지워진 줄 위의 블록 아래로 떨어뜨리기
>>>>>>> 4c45677 (make Loop file)
void Grid::MoveRowDown(int row, int numRows)
{
    for (int column = 0; column < numCols; column++)
    {
        grid[row + numRows][column] = grid[row][column];
        grid[row][column] = 0;
    }
}
// Window창 격자 생성
#pragma once
#include <vector>
#include <raylib.h>

using namespace std;

class Grid
{
public:
	Grid();
	void Initialize(); // 배열을 0으로 초기화
	void Print();
	void Draw(); // grid 배열 그래픽 화면에 그리기
	bool IsCellOutside(int row, int column);
	bool IsCellEmpty(int row, int column);

	int ClearFullRows();

	int grid[20][10];

private:
	bool IsRowFull(int row);

	void ClearRow(int row);
	void MoveRowDown(int row, int numRows);

	int numRows;
	int numCols;
	int cellSize;
	vector<Color> colors;
};
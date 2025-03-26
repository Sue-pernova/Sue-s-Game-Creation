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
<<<<<<< HEAD
	int ClearFullRows();
=======
	int ClearFullRows(); // 줄 삭제
>>>>>>> 4c45677 (make Loop file)
	int grid[20][10]; 

private:
	bool IsRowFull(int row);
<<<<<<< HEAD
	void ClearRow(int row);		
	void MoveRowDown(int row, int numRows);
=======
	void ClearRow(int row);	// 행 전부 0으로 초기화
	void MoveRowDown(int row, int numRows); // 사라진 줄 위의 블럭을 아래로 떨어뜨리는 기능
>>>>>>> 4c45677 (make Loop file)
	int numRows;
	int numCols;
	int cellSize;
	vector<Color> colors;
};
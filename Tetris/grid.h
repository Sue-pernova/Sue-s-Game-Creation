// Windowâ ���� ����
#pragma once
#include <vector>
#include <raylib.h>

using namespace std;

class Grid 
{
public: 
	Grid();
	void Initialize(); // �迭�� 0���� �ʱ�ȭ
	void Print(); 
	void Draw(); // grid �迭 �׷��� ȭ�鿡 �׸���
	bool IsCellOutside(int row, int column);
	bool IsCellEmpty(int row, int column);
<<<<<<< HEAD
	int ClearFullRows();
=======
	int ClearFullRows(); // �� ����
>>>>>>> 4c45677 (make Loop file)
	int grid[20][10]; 

private:
	bool IsRowFull(int row);
<<<<<<< HEAD
	void ClearRow(int row);		
	void MoveRowDown(int row, int numRows);
=======
	void ClearRow(int row);	// �� ���� 0���� �ʱ�ȭ
	void MoveRowDown(int row, int numRows); // ����� �� ���� ���� �Ʒ��� ����߸��� ���
>>>>>>> 4c45677 (make Loop file)
	int numRows;
	int numCols;
	int cellSize;
	vector<Color> colors;
};
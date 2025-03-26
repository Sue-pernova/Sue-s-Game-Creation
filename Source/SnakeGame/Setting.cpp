#include "Setting.h"

// 그리드 만들기 : 750x750 -> 30*25 = 750
int cellSize = 30;
int cellCount = 25;
int canvasSize = cellSize * cellCount;
int offset = 75;

// 색상 선언 및 초기화
Color green = { 173, 204, 96, 255 };
Color darkgreen = { 43, 51, 24, 255 };
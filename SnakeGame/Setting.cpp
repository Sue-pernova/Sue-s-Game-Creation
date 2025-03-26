#include "Setting.h"

// 그리드 만들기 : 750x750 -> 30*25 = 750
int cellSize = 30;
int cellCount = 20;
int canvasSize = cellSize * cellCount;
int offset = 75;

// 색상 선언 및 초기화
Color color = { 200, 191, 231, 255 };
Color deepcolor = { 116, 97, 194, 255 };
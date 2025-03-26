#include <deque>
#include "raylib.h"
#include "Setting.h"
#include "Food.h"
#include <raymath.h>
using namespace std;

bool ElementInDeque(const Vector2& element, const deque<Vector2>& deque) {
	for (int i = 0; i < deque.size(); i++) {
		if (Vector2Equals(element, deque[i])) {
			return true;
		}
	} return false;
}

Vector2 Food::position; // 초기화 없이 정의

Food::Food(const deque<Vector2>& snakeBody) {
	Image image = LoadImage("Graphics/food.png");
	texture = LoadTextureFromImage(image);
	UnloadImage(image);

	position = GenerateRandomPos(snakeBody); // 생성자에서 랜덤 값으로 초기화
}

Food::~Food() {
	UnloadTexture(texture);
}

void Food::Draw() { // 텍스처 그리기 함수
	/*DrawRectangle(position.x * cellSize, position.y * cellSize, cellSize, cellSize, RED);*/
	DrawTexture(texture, offset + position.x * cellSize, offset + position.y * cellSize, RED);
}

void Food::SetPosition(Vector2 newPos) {
	position = newPos;
}

const Vector2& Food::GetPosition() const {
	return position;
}

Vector2 Food::GenerateRandomCell() {
	float x = GetRandomValue(0, cellCount - 1);
	float y = GetRandomValue(0, cellCount - 1);

	return Vector2{ x,y };
}

Vector2 Food::GenerateRandomPos(const deque<Vector2>& snakeBody) { // 랜덤 좌표 생성 함수
	Vector2 pos;
	do {
		pos = GenerateRandomCell();
	} while (ElementInDeque(pos, snakeBody));
	return pos;
}
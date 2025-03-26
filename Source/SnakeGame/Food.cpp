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

Vector2 Food::position; // �ʱ�ȭ ���� ����

Food::Food(const deque<Vector2>& snakeBody) {
	Image image = LoadImage("Graphics/food.png");
	texture = LoadTextureFromImage(image);
	UnloadImage(image);

	position = GenerateRandomPos(snakeBody); // �����ڿ��� ���� ������ �ʱ�ȭ
}

Food::~Food() {
	UnloadTexture(texture);
}

void Food::Draw() { // �ؽ�ó �׸��� �Լ�
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

Vector2 Food::GenerateRandomPos(const deque<Vector2>& snakeBody) { // ���� ��ǥ ���� �Լ�
	Vector2 pos;
	do {
		pos = GenerateRandomCell();
	} while (ElementInDeque(pos, snakeBody));
	return pos;
}
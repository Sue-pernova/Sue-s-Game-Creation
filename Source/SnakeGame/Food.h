#pragma once
#include <deque>
#include "raylib.h"
#include "Setting.h"
using namespace std;

extern bool ElementInDeque(const Vector2& element, const deque<Vector2>& deque);

class Food {
private:
	static Vector2 position;
	Texture2D texture;
public:
	Food(const deque<Vector2>& snakeBody);
	~Food();

	void Draw();

	void SetPosition(Vector2 newPos);
	const Vector2& GetPosition() const; // 객체 상태를 변경X, position 값을 반환

	Vector2 GenerateRandomCell();
	Vector2 GenerateRandomPos(const deque<Vector2>& deque);
};
#include "Snake.h"
#include <raymath.h>

deque<Vector2> Snake::body = { Vector2{6,9}, Vector2{5,9}, Vector2{4,9} };
Vector2 direction = { 1,0 };

bool addSegment = false;

void Snake::Draw() {
	for (int i = 0; i < body.size(); i++) {
		float x = body[i].x;
		float y = body[i].y;
		Rectangle segment = Rectangle{ offset + x * cellSize, offset + y * cellSize, (float)cellSize, (float)cellSize };

		DrawRectangleRounded(segment, 0.5, 6, deepcolor);
	}
}

void Snake::Update() {
	body.push_front(Vector2Add(body[0], direction));

	if (addSegment) {
		addSegment = false;
	}
	else {
		body.pop_back();
	}
}

void Snake::Reset() {
	body = { Vector2{6,9}, Vector2{5,9}, Vector2{4,9} };
	direction = { 1,0 };

}

const deque<Vector2>& Snake::GetDeque() const {
	return body;
}
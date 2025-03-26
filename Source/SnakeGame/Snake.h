#pragma once
#include "raylib.h"
#include "Setting.h"
#include <deque>
using namespace std;

extern Vector2 direction;
extern bool addSegment;

class Snake {
private:
	static deque<Vector2> body;

public:
	void Draw();
	void Update();
	void Reset();
	const deque<Vector2>& GetDeque() const;
};
#pragma once
#include "raylib.h"
#include "Setting.h"
#include "Food.h"
#include "Snake.h"

class Object {
private:
	// °´Ã¼ ¼±¾ð
	Snake snake;
	Food food = Food(snake.GetDeque());

public:
	Object();
	~Object();

	void Draw();
	void Update();
	void GameOver();
	void CheckCollisionWithFood();
	void CheckCollisionWithEdges();
	void CheckCollisionWithTail();
};

class SnakeLoop {
private:
	void startLoop();
public:
	SnakeLoop();
	~SnakeLoop();
	void run();
};
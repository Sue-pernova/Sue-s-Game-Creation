#ifndef SNAKELOOP_H
#define SNAKELOOP_H

#pragma once
#include "raylib.h"
#include "Setting.h"
#include "Food.h"
#include "Snake.h"
#include "../Screen.h"

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
	Music currentBgm;
	void startLoop();
public:
	SnakeLoop(Music& bgm);
	~SnakeLoop();
	void run();
};
#endif
#include "SnakeLoop.h"
#include <raymath.h>


// ������Ʈ�� �ð� ����
double lastUpdateTime = 0;

// ���� �ð��� �������� Ȯ���ϴ� �Լ�
bool eventTriggered(double interval) {
	double currentTime = GetTime();

	if (currentTime - lastUpdateTime >= interval) {
		lastUpdateTime = currentTime;
		return true;
	}
	return false;
}

// ���� ������ Ȯ��
bool running = false;

// ���ھ� ����
int score = 0;

// ���� ����
Sound eatSound;
Sound wallSound;

// Object Ŭ����
Object::Object() {
	InitAudioDevice();
	eatSound = LoadSound("Sounds/eat.mp3");
	wallSound = LoadSound("Sounds/wall.mp3");
}

Object::~Object() {
	UnloadSound(eatSound);
	UnloadSound(wallSound);
	CloseAudioDevice();
}

void Object::Draw() {
	food.Draw();
	snake.Draw();
}

void Object::Update() {
	if (running) {
		snake.Update();
		CheckCollisionWithFood();
		CheckCollisionWithEdges();
		CheckCollisionWithTail();
	}
}

void Object::GameOver(){
	snake.Reset();
	food.GenerateRandomPos(snake.GetDeque());
	running = false;
	score = 0;
	PlaySound(wallSound);
}

void Object::CheckCollisionWithFood() {
	if (Vector2Equals(snake.GetDeque()[0], food.GetPosition())) {
		food.SetPosition(food.GenerateRandomPos(snake.GetDeque()));
		addSegment = true;
		score++;
		PlaySound(eatSound);
	}
}
void Object::CheckCollisionWithEdges() {
	if (snake.GetDeque()[0].x == cellCount || snake.GetDeque()[0].x == -1) {
		GameOver();
	}
	if (snake.GetDeque()[0].y == cellCount || snake.GetDeque()[0].y == -1) {
		GameOver();
	}
}

void Object::CheckCollisionWithTail() {
	deque<Vector2> headless = snake.GetDeque();
	headless.pop_front();

	if (ElementInDeque(snake.GetDeque()[0], headless)) {
		GameOver();
	}
}

// SnakeLoop Ŭ����
// ������
SnakeLoop::SnakeLoop() {
	// �� ���� ������ ���� �Լ�
	InitWindow(offset * 2 + canvasSize, offset * 2 + canvasSize, "Snake Game");
	// ���� ���� �ӵ� ���� �Լ�
	SetTargetFPS(60);
}

// �Ҹ���
SnakeLoop::~SnakeLoop() {
	CloseWindow();
}

void SnakeLoop::run() {
	startLoop();
}

void SnakeLoop::startLoop() {
	Object ob = Object();

	while (!WindowShouldClose()) { // ���� ���� �ൿ(esc �Է� �� �ݱ� ��ư Ŭ�� ���� Ȯ��)
		BeginDrawing();  // �� ĵ���� ����

		ClearBackground(green); // ���ȭ�� �� �ʱ�ȭ
		DrawRectangleLinesEx(Rectangle{ (float)offset - 7, (float)offset - 7, (float)canvasSize + 14, (float)canvasSize + 14 }, 7, darkgreen);
		DrawText("Retro Snake", offset - 5, 20, 40, darkgreen);
		DrawText(TextFormat("Score : %i", score), canvasSize/2 + offset, 20, 40, darkgreen);
		ob.Draw();

		if (eventTriggered(0.2)) { // 0.2�� �������� ��ġ ������Ʈ
			ob.Update();
		}

		if (IsKeyPressed(KEY_UP) && direction.y != 1) {
			direction = { 0, -1 };
			running = true;
		}
		if (IsKeyPressed(KEY_DOWN) && direction.y != -1) {
			direction = { 0, 1 };
			running = true;
		}
		if (IsKeyPressed(KEY_LEFT) && direction.x != 1) {
			direction = { -1, 0 };
			running = true;
		}
		if (IsKeyPressed(KEY_RIGHT) && direction.x != -1) {
			direction = { 1, 0 };
			running = true;
		}

		EndDrawing();  // ĵ���� �ݱ�
	}
}
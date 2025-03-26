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
int hearts = 3; // �ʱ� ��ȸ�� 3��

// ���� ����
Sound eatSound;
Sound wallSound;

// Object Ŭ����
Object::Object() {
	eatSound = LoadSound("Sounds/eat.mp3");
	wallSound = LoadSound("Sounds/wall.mp3");
}

Object::~Object() {
	UnloadSound(eatSound);
	UnloadSound(wallSound);
}

void Object::Draw() {
	food.Draw();
	snake.Draw();
}

void Object::Update() {
	if (running && hearts > 0) {
		snake.Update();
		CheckCollisionWithFood();
		CheckCollisionWithEdges();
		CheckCollisionWithTail();
	}
}

void Object::GameOver(){
	PlaySound(wallSound);
	if (hearts > 1) {
		hearts--;  // ��ȸ ����
		snake.Reset();
		food.GenerateRandomPos(snake.GetDeque());
		running = false;
		score = 0;
	}
	else {
		// ��ȸ�� ��� �����Ǹ� ENDING ȭ������ ��ȯ
		running = false;
		currentWindow = ENDING;
	}
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
SnakeLoop::SnakeLoop(Music& bgm) {
	currentBgm = bgm;  // �����ڿ��� ���޹��� ���� ��ü ����
}

// �Ҹ���
SnakeLoop::~SnakeLoop() {
}

void SnakeLoop::run() {
	startLoop();
}

void SnakeLoop::startLoop() {
	Object ob = Object();

	while (!WindowShouldClose()) { // ���� ���� �ൿ(esc �Է� �� �ݱ� ��ư Ŭ�� ���� Ȯ��)
		if (IsKeyPressed(KEY_ESCAPE)) {
			currentWindow = ENDING; // ESC Ű�� ������ ���� ����
			break;
		}

		if (currentWindow == ENDING) {  // ENDING ȭ������ ��ȯ�Ǹ� ���� ����
			break;
		}

		UpdateMusicStream(currentBgm);
		BeginDrawing();  // �� ĵ���� ����

		ClearBackground(color); // ���ȭ�� �� �ʱ�ȭ
		DrawRectangleLinesEx(Rectangle{ (float)offset - 7, (float)offset - 7, (float)canvasSize + 14, (float)canvasSize + 14 }, 7, deepcolor);
		DrawText("Retro Snake", offset - 5, 20, 35, deepcolor);
		DrawText(TextFormat("Score : %i", score), offset - 5, canvasSize + offset +15, 35, deepcolor);
		DrawText(TextFormat("Hearts : %i", hearts), canvasSize - 150, 20, 35, deepcolor);
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
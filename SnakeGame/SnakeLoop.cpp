#include "SnakeLoop.h"
#include <raymath.h>


// 업데이트용 시간 변수
double lastUpdateTime = 0;

// 일정 시간이 지났는지 확인하는 함수
bool eventTriggered(double interval) {
	double currentTime = GetTime();

	if (currentTime - lastUpdateTime >= interval) {
		lastUpdateTime = currentTime;
		return true;
	}
	return false;
}

// 게임 실행중 확인
bool running = false;

// 스코어 변수
int score = 0;
int hearts = 3; // 초기 기회는 3번

// 사운드 변수
Sound eatSound;
Sound wallSound;

// Object 클래스
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
		hearts--;  // 기회 차감
		snake.Reset();
		food.GenerateRandomPos(snake.GetDeque());
		running = false;
		score = 0;
	}
	else {
		// 기회가 모두 소진되면 ENDING 화면으로 전환
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

// SnakeLoop 클래스
// 생성자
SnakeLoop::SnakeLoop(Music& bgm) {
	currentBgm = bgm;  // 생성자에서 전달받은 음악 객체 설정
}

// 소멸자
SnakeLoop::~SnakeLoop() {
}

void SnakeLoop::run() {
	startLoop();
}

void SnakeLoop::startLoop() {
	Object ob = Object();

	while (!WindowShouldClose()) { // 게임 종료 행동(esc 입력 및 닫기 버튼 클릭 여부 확인)
		if (IsKeyPressed(KEY_ESCAPE)) {
			currentWindow = ENDING; // ESC 키를 누르면 게임 종료
			break;
		}

		if (currentWindow == ENDING) {  // ENDING 화면으로 전환되면 게임 종료
			break;
		}

		UpdateMusicStream(currentBgm);
		BeginDrawing();  // 빈 캔버스 생성

		ClearBackground(color); // 배경화면 색 초기화
		DrawRectangleLinesEx(Rectangle{ (float)offset - 7, (float)offset - 7, (float)canvasSize + 14, (float)canvasSize + 14 }, 7, deepcolor);
		DrawText("Retro Snake", offset - 5, 20, 35, deepcolor);
		DrawText(TextFormat("Score : %i", score), offset - 5, canvasSize + offset +15, 35, deepcolor);
		DrawText(TextFormat("Hearts : %i", hearts), canvasSize - 150, 20, 35, deepcolor);
		ob.Draw();

		if (eventTriggered(0.2)) { // 0.2초 간격으로 위치 업데이트
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

		EndDrawing();  // 캔버스 닫기
	}
}
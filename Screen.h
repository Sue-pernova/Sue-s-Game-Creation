#pragma once
#include "Button.h"

enum Window {TITLE, SELECT, SNAKE, TETRIS, ENDING};
extern Window currentWindow;

class Screen {
	// 스크린이 가지고 잇어야하는 속성
	// 기존 스크린을 활용해야하는 편인데? -> 스크린 크기 수정, 스크린 타이틀 수정
public:
	// 스크린이 가지고 있어야하는 함수
	// 스크린 그리기, 상태 업데이트?
	virtual void Update() = 0;
	virtual void Draw() = 0;
};

// Title
class TitleScreen : public Screen{
private:
	Texture2D background;
	Button startbtn;
public:
	TitleScreen();
	~TitleScreen();
	void Update() override;
	void Draw() override;
};

// SelectGame
class SelectScreen : public Screen {
private:
	Texture2D background;
	Button snakebtn;
	Button tetrisbtn;
public:
	SelectScreen();
	~SelectScreen();
	void Update() override;
	void Draw() override;
};

// SnakeGame
class SnakeScreen : public Screen {
private:
	Music& currentBgm;
public:
	SnakeScreen(Music& bgm) : currentBgm(bgm) {}
	void Update() override;
	void Draw() override;
};

// Tetris
class TetrisScreen : public Screen {
private:
	Music& currentBgm;
public:
	TetrisScreen(Music& bgm) : currentBgm(bgm) {}
	void Update() override;
	void Draw() override;
};

// Ending
class EndingScreen : public Screen {
private:
	Texture2D background;
	Button ending;
public:
	EndingScreen();
	~EndingScreen();
	void Update() override;
	void Draw() override;
};

#pragma once
#include "Button.h"

enum Window {TITLE, SELECT, SNAKE, TETRIS, ENDING};
extern Window currentWindow;

class Screen {
	// ��ũ���� ������ �վ���ϴ� �Ӽ�
	// ���� ��ũ���� Ȱ���ؾ��ϴ� ���ε�? -> ��ũ�� ũ�� ����, ��ũ�� Ÿ��Ʋ ����
public:
	// ��ũ���� ������ �־���ϴ� �Լ�
	// ��ũ�� �׸���, ���� ������Ʈ?
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

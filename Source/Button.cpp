#include "Button.h"


Button::Button(const char* imagePath, Vector2 imagePosition, float scale) {
	Image image = LoadImage(imagePath);

	int originW = image.width;
	int originH = image.height;

	int newW = static_cast<int>(originW * scale);
	int newH = static_cast<int>(originH * scale);

	ImageResize(&image, newW, newH);
	texture = LoadTextureFromImage(image);
	UnloadImage(image);
	position = imagePosition;
}

Button::~Button() {
	UnloadTexture(texture);
}

void Button::Draw() {
	DrawTextureV(texture, position, WHITE);
}

bool Button::isPressed(Vector2 mousePos, bool mousePressed) {
	Rectangle rect = { position.x, position.y, static_cast<float>(texture.width), static_cast<float>(texture.height) };

	// 마우스 위치가 사각형 위이면서 마우스가 눌려지면 true, 그게 아니면 false
	if (CheckCollisionPointRec(mousePos, rect) && mousePressed) {
		return true;
	}
	return false;
}
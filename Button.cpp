#include "Button.h"

// 이미지 로드 및 리사이징 함수
Texture2D Button::LoadTextureResized(const char* imagePath, float scale) {
    Image img = LoadImage(imagePath);
    ImageResize(&img, img.width * scale, img.height * scale);
    Texture2D tex = LoadTextureFromImage(img);
    UnloadImage(img);
    return tex;
}

// 버튼 생성자 (이미지 & 사운드 로드)
Button::Button(const char* defaultImg, const char* hoverImg, const char* soundFile, Vector2 pos, float scale)
    : defaultImg(LoadTextureResized(defaultImg, scale)),
    hoverImg(LoadTextureResized(hoverImg, scale)),
    position(pos), isHovered(false) {

    hoverSound = LoadSound(soundFile);  // 사운드 로드
}

Button::~Button() {
    UnloadTexture(defaultImg);
    UnloadTexture(hoverImg);
    UnloadSound(hoverSound);
}

void Button::Draw() {
    DrawTextureV(isHovered ? hoverImg : defaultImg, position, WHITE);
}

bool Button::isPressed(Vector2 mousePos, bool mousePressed) {
    Rectangle rect = { position.x, position.y, (float)defaultImg.width, (float)defaultImg.height };
    return CheckCollisionPointRec(mousePos, rect) && mousePressed;
}

void Button::Update(Vector2 mousePos) {
    Rectangle rect = { position.x, position.y, (float)defaultImg.width, (float)defaultImg.height };
    bool newHoverState = CheckCollisionPointRec(mousePos, rect);

    if (!isHovered && newHoverState) {
        PlaySound(hoverSound);  // Hover 처음 진입 시 사운드 재생
    }

    isHovered = newHoverState;
}

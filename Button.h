#pragma once
#include "raylib.h"

class Button {
private:
    Texture2D defaultImg;
    Texture2D hoverImg;
    Vector2 position;
    bool isHovered;
    Sound hoverSound;

    Texture2D LoadTextureResized(const char* imagePath, float scale);

public:
    Button(const char* defaultImg, const char* hoverImg, const char* soundFile, Vector2 pos, float scale);
    ~Button();

    void Draw();
    bool isPressed(Vector2 mousePos, bool mousePressed);
    void Update(Vector2 mousePos);
};

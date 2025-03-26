#ifndef TETRIS_LOOP_H
#define TETRIS_LOOP_H
// ifndef, define, endif: �ش� ��� ������ �� �� �̻� ���ԵǴ� ���� �����ϴ� ��ũ��
// �ߺ� ���� ������ ��������

#include <raylib.h>
#include "game.h"

class TetrisLoop
{
public:
    // ������
    TetrisLoop();

    // �Ҹ���
    ~TetrisLoop();
    void Run();

private:
    // �� �ڵ� ����
    bool EventTriggered(double interval);

    // ���� ����
    Game game;

    Font font;

    double lastUpdateTime;
};

#endif
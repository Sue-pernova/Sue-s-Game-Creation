#include "TetrisLoop.h"
#include <ctime>
#include <cstdlib>

int main() 
{
    srand(time(NULL));
    TetrisLoop loop;
    loop.Run();
    return 0;
}
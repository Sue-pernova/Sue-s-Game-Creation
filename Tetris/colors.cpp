#include "colors.h"

using namespace std;

const Color darkGrey = { 246, 245, 242, 255 };
const Color green = { 172, 211, 168, 255 };
const Color red = { 236, 82, 40, 255 };
const Color orange = { 209, 187, 158, 255 };
const Color yellow = { 243, 140, 121, 255 };
const Color purple = { 198, 142, 253, 255 };
const Color cyan = { 143, 135, 241, 255 };
const Color blue = { 210, 224, 251, 255 };
const Color lightPink = { 254, 210, 226, 255 };
const Color darkPink = { 255, 164, 179, 255 };

vector<Color> GetCellColors()
{
    return { darkGrey, green, red, orange, yellow, purple, cyan, blue };
}
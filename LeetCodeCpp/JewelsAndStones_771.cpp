#include "JewelsAndStones_771.h"

int JewelsAndStones_771::numJewelsInStones(string jewels, string stones)
{
    bool isJewel[128] = {false};                 // ASCII lookup table
    for (char c : jewels)
        isJewel[static_cast<unsigned char>(c)] = true;

    int cnt = 0;
    for (char c : stones)
        if (isJewel[static_cast<unsigned char>(c)])
            ++cnt;

    return cnt;
}

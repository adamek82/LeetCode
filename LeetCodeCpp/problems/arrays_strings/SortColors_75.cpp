#include "SortColors_75.h"
#include <array>

void SortColors_75::sortColors_threeTails(vector<int>& nums)
{
    int zeroEnd = -1;
    int oneEnd = -1;
    int twoEnd = -1;

    for (int color : nums) {
        if (color == 0) {
            nums[++twoEnd] = 2;
            nums[++oneEnd] = 1;
            nums[++zeroEnd] = 0;
        } else if (color == 1) {
            nums[++twoEnd] = 2;
            nums[++oneEnd] = 1;
        } else {
            nums[++twoEnd] = 2;
        }
    }
}

void SortColors_75::sortColors_counting(vector<int>& nums)
{
    enum Color {
        Red,
        White,
        Blue,
        ColorCount
    };

    array<int, ColorCount> counts{};

    for (int color : nums)
        ++counts[color];

    size_t write = 0;

    for (int color = Red; color <= Blue; ++color) {
        for (int count = 0; count < counts[color]; ++count)
            nums[write++] = color;
    }
}

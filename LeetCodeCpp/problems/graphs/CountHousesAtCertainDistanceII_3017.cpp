#include "CountHousesAtCertainDistanceII_3017.h"

#include <vector>

using namespace std;

vector<long long> CountHousesAtCertainDistanceII_3017::countOfPairs(
    int n, int x, int y) {
    --x;
    --y;

    if (x > y) {
        swap(x, y);
    }

    vector<long long> diff(n);

    for (int i = 0; i < n; ++i) {
        const int distanceToX =
            min(abs(i - x), abs(i - y) + 1);

        const int distanceToY =
            min(abs(i - y), abs(i - x) + 1);

        const int distanceToLeftEnd =
            min(abs(i),
                abs(i - y) + 1 + x);

        const int distanceToRightEnd =
            min(abs(i - (n - 1)),
                abs(i - x) + 1 + (n - 1 - y));

        const int distanceToCycle =
            max(x - i, 0) + max(i - y, 0);

        const int firstCycleEnd =
            distanceToCycle + (y - x) / 2;

        const int secondCycleEnd =
            distanceToCycle + (y - x + 1) / 2;

        diff[0] += 2;

        ++diff[distanceToX];
        ++diff[distanceToY];

        --diff[distanceToLeftEnd];
        --diff[distanceToRightEnd];

        --diff[firstCycleEnd];
        --diff[secondCycleEnd];
    }

    for (int distance = 1; distance < n; ++distance) {
        diff[distance] += diff[distance - 1];
    }

    return diff;
}

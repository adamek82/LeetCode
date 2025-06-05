#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class MaximalRectangle_85 {
public:
    int maximalRectangle(vector<vector<char>>& matrix);
private:
    int largestRectangleArea(const vector<int>& heights);
};
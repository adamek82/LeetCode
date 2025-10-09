#pragma once
#include <vector>

using namespace std;

class CourseScheduleII_210 {
public:
    vector<int> findOrderByDFSTraversal(int numCourses, vector<vector<int>>& prerequisites);
    vector<int> findOrderByKahnsAlgorithm(int numCourses, vector<vector<int>>& prerequisites);
};

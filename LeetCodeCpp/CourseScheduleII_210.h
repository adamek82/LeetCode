#pragma once
#include <vector>
#include <unordered_map>
#include <functional>
#include <queue>

class CourseScheduleII_210 {
public:
    std::vector<int> findOrderByDFSTraversal(int numCourses, std::vector<std::vector<int>>& prerequisites);
    std::vector<int> findOrderByKahnsAlgorithm(int numCourses, std::vector<std::vector<int>>& prerequisites);
};

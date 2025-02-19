#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>

class AnalyzeUserWebsiteVisitPattern1152 {
public:
    std::vector<std::string> mostVisitedPattern_usingMap(std::vector<std::string>& username, std::vector<int>& timestamp, std::vector<std::string>& website);
    std::vector<std::string> mostVisitedPattern_usingHashmap(std::vector<std::string>& username, std::vector<int>& timestamp, std::vector<std::string>& website);
};
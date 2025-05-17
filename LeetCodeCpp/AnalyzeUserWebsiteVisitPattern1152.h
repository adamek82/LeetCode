#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>

using namespace std;

class AnalyzeUserWebsiteVisitPattern1152 {
public:
    vector<string> mostVisitedPattern_usingMap(vector<string>& username, vector<int>& timestamp, vector<string>& website);
    vector<string> mostVisitedPattern_usingHashmap(vector<string>& username, vector<int>& timestamp, vector<string>& website);
};
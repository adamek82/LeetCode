#include "AnalyzeUserWebsiteVisitPattern1152.h"

std::vector<std::string> AnalyzeUserWebsiteVisitPattern1152::mostVisitedPattern_usingMap(std::vector<std::string> &username, std::vector<int> &timestamp, std::vector<std::string> &website)
{
    // Step 1: Sort users by timestamp
    std::vector<std::tuple<int, std::string, std::string>> logs; // (timestamp, username, website)
    for (size_t i = 0; i < username.size(); ++i) {
        logs.emplace_back(timestamp[i], username[i], website[i]);
    }
    sort(logs.begin(), logs.end());

    // Step 2: Group websites visited by each user
    std::unordered_map<std::string, std::vector<std::string>> userToSites;
    for (const auto& [ts, user, site] : logs) {
        userToSites[user].push_back(site);
    }

    // Step 3: Count frequency of each 3-sequence pattern
    std::map<std::vector<std::string>, int> patternCount;
    for (const auto& [user, sites] : userToSites) {
        if (sites.size() < 3) continue;
        std::set<std::vector<std::string>> uniquePatterns;

        // Generate all unique 3-sequences
        for (size_t i = 0; i < sites.size(); ++i) {
            for (size_t j = i + 1; j < sites.size(); ++j) {
                for (size_t k = j + 1; k < sites.size(); ++k) {
                    uniquePatterns.insert({sites[i], sites[j], sites[k]});
                }
            }
        }

        // Update pattern count
        for (const auto& pattern : uniquePatterns) {
            patternCount[pattern]++;
        }
    }

    // Step 4: Find the most visited pattern (sorted lexicographically in case of ties)
    return max_element(patternCount.begin(), patternCount.end(),
                       [](const auto& a, const auto& b) {
                           return a.second < b.second || (a.second == b.second && a.first > b.first);
                       })->first;
}

// Define a custom hash function for vector<string>
struct VectorHash {
    size_t operator()(const std::vector<std::string>& v) const {
        size_t hashValue = 0;
        std::hash<std::string> hasher;
        for (const auto& s : v) {
            hashValue ^= hasher(s) + 0x9e3779b9 + (hashValue << 6) + (hashValue >> 2);
        }
        return hashValue;
    }
};

std::vector<std::string> AnalyzeUserWebsiteVisitPattern1152::mostVisitedPattern_usingHashmap(std::vector<std::string> &username, std::vector<int> &timestamp, std::vector<std::string> &website)
{
    int n = username.size();
    std::vector<std::tuple<int, std::string, std::string>> visits; // {timestamp, username, website}

    // Step 1: Collect and sort visits by timestamp
    for (int i = 0; i < n; i++) {
        visits.emplace_back(timestamp[i], username[i], website[i]);
    }
    sort(visits.begin(), visits.end()); // Sort by timestamp

    // Step 2: Group websites visited by each user in chronological order
    std::unordered_map<std::string, std::vector<std::string>> userVisits;
    for (const auto& [time, user, site] : visits) {
        userVisits[user].push_back(site);
    }

    // Step 3: Count occurrences of each unique 3-sequence pattern
    std::unordered_map<std::vector<std::string>, std::unordered_set<std::string>, VectorHash> patternCount;

    for (const auto& [user, sites] : userVisits) {
        int m = sites.size();
        if (m < 3) continue; // User must have visited at least 3 sites

        std::set<std::vector<std::string>> uniquePatterns; // To avoid duplicate 3-sequences per user
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                for (int k = j + 1; k < m; k++) {
                    uniquePatterns.insert({sites[i], sites[j], sites[k]});
                }
            }
        }

        // Add patterns for the current user
        for (const auto& pattern : uniquePatterns) {
            patternCount[pattern].insert(user);
        }
    }

    // Step 4: Find the most visited pattern
    std::vector<std::string> result;
    int maxUsers = 0;

    for (const auto& [pattern, users] : patternCount) {
        int count = users.size();
        if (count > maxUsers || (count == maxUsers && pattern < result)) {
            maxUsers = count;
            result = pattern;
        }
    }

    return result;
}

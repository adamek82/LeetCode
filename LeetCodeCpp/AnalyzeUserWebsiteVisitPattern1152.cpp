#include "AnalyzeUserWebsiteVisitPattern1152.h"

std::vector<std::string> AnalyzeUserWebsiteVisitPattern1152::mostVisitedPattern(std::vector<std::string> &username, std::vector<int> &timestamp, std::vector<std::string> &website)
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
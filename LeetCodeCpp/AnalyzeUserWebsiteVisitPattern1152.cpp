#include "AnalyzeUserWebsiteVisitPattern1152.h"

vector<string> AnalyzeUserWebsiteVisitPattern1152::mostVisitedPattern_usingMap(vector<string> &username, vector<int> &timestamp, vector<string> &website)
{
    // Step 1: Sort users by timestamp
    vector<tuple<int, string, string>> logs; // (timestamp, username, website)
    for (size_t i = 0; i < username.size(); ++i) {
        logs.emplace_back(timestamp[i], username[i], website[i]);
    }
    sort(logs.begin(), logs.end());

    // Step 2: Group websites visited by each user
    unordered_map<string, vector<string>> userToSites;
    for (const auto& [ts, user, site] : logs) {
        userToSites[user].push_back(site);
    }

    // Step 3: Count frequency of each 3-sequence pattern
    map<vector<string>, int> patternCount;
    for (const auto& [user, sites] : userToSites) {
        if (sites.size() < 3) continue;
        set<vector<string>> uniquePatterns;

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
// This allows unordered_map to use vector<string> as a key.
struct VectorHash {
    size_t operator()(const vector<string>& v) const {
        size_t hashValue = 0;
        hash<string> hasher;

        // Combine hashes of individual strings using bitwise operations
        for (const auto& s : v) {
            // ^  (XOR): Mixes hash values to reduce collisions
            // 0x9e3779b9: Golden ratio multiplier, helps spread bits uniformly
            // << 6: Left shift to amplify changes in higher bits
            // >> 2: Right shift to mix high bits into low bits, improving distribution
            hashValue ^= hasher(s) + 0x9e3779b9 + (hashValue << 6) + (hashValue >> 2);
        }

        return hashValue;
    }
};

vector<string> AnalyzeUserWebsiteVisitPattern1152::mostVisitedPattern_usingHashmap(vector<string> &username, vector<int> &timestamp, vector<string> &website)
{
    int n = username.size();
    vector<tuple<int, string, string>> visits; // {timestamp, username, website}

    // Step 1: Collect and sort visits by timestamp
    for (int i = 0; i < n; i++) {
        visits.emplace_back(timestamp[i], username[i], website[i]);
    }
    sort(visits.begin(), visits.end()); // Sort by timestamp

    // Step 2: Group websites visited by each user in chronological order
    unordered_map<string, vector<string>> userVisits;
    for (const auto& [time, user, site] : visits) {
        userVisits[user].push_back(site);
    }

    // Step 3: Count occurrences of each unique 3-sequence pattern
    unordered_map<vector<string>, unordered_set<string>, VectorHash> patternCount;

    for (const auto& [user, sites] : userVisits) {
        int m = sites.size();
        if (m < 3) continue; // User must have visited at least 3 sites

        set<vector<string>> uniquePatterns; // To avoid duplicate 3-sequences per user
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
    vector<string> result;
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

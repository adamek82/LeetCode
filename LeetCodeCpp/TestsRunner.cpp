#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <optional>
#include <cmath>
#include <variant>
#include <numeric>
#include "TestCases.h"
#include "TestUtils.h"
#include "TestRegistry.h"
#include "TestsBasicArraysStrings.h"
#include "TestsArrayInPlace.h"
#include "TestsArrayGreedyTransform.h"
#include "TestsGraphs.h"
#include "TestsTrees.h"
#include "TestsLinkedLists.h"
#include "TestsDynamicProgramming.h"
#include "TestsHashmapsSets.h"
#include "TestsTwoPointers.h"
#include "TestsStacks.h"
#include "TestsBinarySearch.h"
#include "TestsSlidingWindow.h"
#include "TestsHeaps.h"
#include "TestsBacktracking.h"
#include "TestsBitManipulation.h"
#include "TestsDesign.h"
#include "TestsOther.h"
#include "ListUtils.h"
#include "TreeUtils.h"
#include "BestTimeToBuyAndSellStock_121.h"
#include "SpiralMatrix_54.h"
#include "KthLargestElementInArray_215.h"
#include "RotateImage_48.h"
#include "MergeIntervals_56.h"
#include "ProductOfArrayExceptSelf.h"
#include "MajorityElement_169.h"
#include "ValidSudoku_36.h"
#include "ZigzagConversion_6.h"
#include "HIndex_274.h"
#include "SortColors_75.h"
#include "RemoveDuplicatesFromSortedArrayII_80.h"
#include "BestTimeToBuyAndSellStockII_122.h"
#include "ValidAnagram_242.h"
#include "AnalyzeUserWebsiteVisitPattern1152.h"
#include "GroupAnagrams_49.h"
#include "LongestConsecutiveSequence_128.h"
#include "SortCharactersByFrequency_451.h"
#include "TopKFrequentWords_692.h"
#include "TwoSum_1.h"
#include "MergeSortedArray_88.h"
#include "RemoveElement_27.h"
#include "MaximumNumberOfBalloons_1189.h"
#include "FindPivotIndex_724.h"
#include "JewelsAndStones_771.h"
#include "ContainsDuplicate_217.h"
#include "RemoveDuplicates_26.h"
#include "LongestIncreasingPathInMatrix_329.h"
#include "SplitTheArray_3046.h"
#include "RansomNote_383.h"
#include "IslandPerimeter_463.h"
#include "AppleRedistributionIntoBoxes_3074.h"
#include "UniqueNumberOfOccurrences_1207.h"
#include "DesignHashMap_706.h"
#include "PascalsTriangle_118.h"
#include "SlidingPuzzle_773.h"

using namespace std;
using namespace TestUtils;
using namespace TestCases;

class TestsRunner {
private:
    static void appendTests(vector<TestRegistry::Entry>& dst,
                            const vector<TestRegistry::Entry>& src) {
        dst.insert(dst.end(), src.begin(), src.end());
    }

    static vector<TestRegistry::Entry> getTests() {
        vector<TestRegistry::Entry> tests;

        appendTests(tests, TestsBasicArraysStrings::getTests());
        appendTests(tests, TestsArrayInPlace::getTests());
        appendTests(tests, TestsArrayGreedyTransform::getTests());

        appendTests(tests, TestsHashmapsSets::getTests());
        appendTests(tests, TestsTwoPointers::getTests());
        appendTests(tests, TestsStacks::getTests());
        appendTests(tests, TestsLinkedLists::getTests());
        appendTests(tests, TestsBinarySearch::getTests());
        appendTests(tests, TestsSlidingWindow::getTests());
        appendTests(tests, TestsTrees::getTests());
        appendTests(tests, TestsHeaps::getTests());
        appendTests(tests, TestsBacktracking::getTests());
        appendTests(tests, TestsGraphs::getTests());
        appendTests(tests, TestsDynamicProgramming::getTests());
        appendTests(tests, TestsBitManipulation::getTests());
        appendTests(tests, TestsDesign::getTests());
        appendTests(tests, TestsOther::getTests());

        return tests;
    }

public:
    static bool runAllTests() {
        return TestRegistry::runAllTests(getTests());
    }
};

int main() {
    cout << "Running LeetCodeCpp tests:\n";
    TestsRunner::runAllTests();
    return 0;
}

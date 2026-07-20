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

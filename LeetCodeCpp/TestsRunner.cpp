#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <optional>
#include <cmath>
#include <variant>
#include <numeric>
#include "tests/framework/TestCases.h"
#include "tests/framework/TestUtils.h"
#include "tests/framework/TestRegistry.h"
#include "tests/suites/arrays_strings/TestsBasicArraysStrings.h"
#include "tests/suites/arrays_strings/TestsArrayInPlace.h"
#include "tests/suites/arrays_strings/TestsArrayGreedyTransform.h"
#include "tests/suites/graphs/TestsGraphs.h"
#include "tests/suites/trees/TestsTrees.h"
#include "tests/suites/linked_lists/TestsLinkedLists.h"
#include "tests/suites/dynamic_programming/TestsDynamicProgramming.h"
#include "tests/suites/hashmaps_sets/TestsHashmapsSets.h"
#include "tests/suites/two_pointers/TestsTwoPointers.h"
#include "tests/suites/stacks/TestsStacks.h"
#include "tests/suites/binary_search/TestsBinarySearch.h"
#include "tests/suites/sliding_window/TestsSlidingWindow.h"
#include "tests/suites/heaps/TestsHeaps.h"
#include "tests/suites/backtracking/TestsBacktracking.h"
#include "tests/suites/bit_manipulation/TestsBitManipulation.h"
#include "tests/suites/design/TestsDesign.h"
#include "tests/suites/other/TestsOther.h"
#include "common/ListUtils.h"
#include "common/TreeUtils.h"

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

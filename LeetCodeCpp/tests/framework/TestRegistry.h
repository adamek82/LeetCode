#pragma once

#include <cstddef>
#include <iostream>
#include <vector>

namespace TestRegistry {

using TestFn = bool (*)();

struct Entry {
    int id;             // 0 for custom/non-LeetCode tests
    const char* title;  // human-readable title
    TestFn fn;
};

inline Entry makeEntry(int id, const char* title, TestFn fn) {
    return Entry{id, title, fn};
}

inline void printTestHeader(const Entry& test, std::ostream& out = std::cout) {
    out << "Running " << test.title;
    if (test.id > 0) {
        out << " (#" << test.id << ")";
    }
    out << " tests:\n";
}

inline void printFailureStop(const Entry& test, std::ostream& out = std::cout) {
    out << "Stopping after first failing test suite: " << test.title;
    if (test.id > 0) {
        out << " (#" << test.id << ")";
    }
    out << '\n';
}

inline bool runAllTests(const Entry* begin,
                        const Entry* end,
                        std::ostream& out = std::cout) {
    for (const Entry* it = begin; it != end; ++it) {
        const Entry& test = *it;

        printTestHeader(test, out);

        if (!test.fn()) {
            printFailureStop(test, out);
            return false;
        }
    }

    return true;
}

template <size_t N>
inline bool runAllTests(const Entry (&tests)[N],
                        std::ostream& out = std::cout) {
    return runAllTests(tests, tests + N, out);
}

inline bool runAllTests(const std::vector<Entry>& tests,
                        std::ostream& out = std::cout) {
    return runAllTests(tests.data(), tests.data() + tests.size(), out);
}

} // namespace TestRegistry

#define TEST(ID, TITLE, FN) ::TestRegistry::makeEntry((ID), (TITLE), &(FN))

#define REQUIRE_ASSERT(EXPR)        \
    do {                            \
        if (!(EXPR)) return false;  \
    } while (false)

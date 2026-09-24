# Repository conventions

## General

* Keep changes focused on the requested task. Preserve unrelated local changes and do not
  modify or stage unrelated files.
* Before changing code, inspect nearby implementations, tests, and build configuration.
  Reuse existing repository infrastructure and follow `.editorconfig` and local conventions.
* After code changes, build the affected project and run the relevant tests unless explicitly
  told otherwise. Report anything that could not be validated.
* Commit only when explicitly requested, staging only task-related files. Never push unless
  explicitly requested.

## C++

These rules apply to `LeetCodeCpp` and take precedence over inconsistent older code.

* Put solutions in the appropriate `problems/<category>/` directory, normally as matching
  `ProblemName_<id>.h` and `.cpp` files.
* Headers: use `#pragma once`, never `using namespace std;`, and qualify standard-library names.
* Solution `.cpp` files: use `using namespace std;` and avoid unnecessary `std::` prefixes.
* Put opening braces for function definitions on a new line. Use four-space indentation and
  follow nearby formatting.
* Prefer concise, self-documenting code. Comment only non-obvious reasoning, invariants,
  constraints, or tricks.
* Prefer `const`, `size_t` for container indices, and `reserve()` where appropriate.
* Prefer the simplest practical solution that meets the required time and space complexity.
  Avoid unnecessary containers, allocation, generality, and optimizations that reduce clarity.

## Tests

* Extend the appropriate existing suite under `tests/suites/<category>/`; do not create a
  separate test executable or framework for an individual problem.
* Add test-case types to `tests/test_cases/TestCases<Category>.h` in namespace `TestCases`.
  Reuse existing test helpers and utilities.
* Follow the existing test structure: anonymous-namespace `bool` functions,
  `REQUIRE_ASSERT`, and registration with `TEST(id, "Problem title", function)`.
* Use a small representative set covering meaningful edge cases and implementation-sensitive
  paths. Around 8-10 cases is typical, not a target.

## C++ build on Windows

Run from `LeetCodeCpp`:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\build.ps1 -Config Debug
if ($LASTEXITCODE -ne 0) { throw "C++ build failed." }
.\build\Debug\TestsRunner.exe
```

On other platforms, use the repository's existing build workflow. Do not introduce
machine-specific absolute paths.

# Repository conventions

## Repository-wide rules

- These rules apply to all language projects. Each `LeetCode*` directory has its own
  implementation and test layout; `Docs/` holds algorithm notes and longer explanations.
- Keep changes focused on the requested task. Do not modify unrelated files, and preserve
  existing unrelated local changes.
- Inspect the affected project, nearby code, tests, and build configuration before adding
  files or choosing where code and tests belong. Reuse existing infrastructure instead of
  creating parallel mechanisms. Respect `.editorconfig` and local formatting conventions.
- Prefer small, representative test sets over redundant cases. Include meaningful edge
  cases and corner cases specific to the implementation.
- After code changes, build the affected project and run the relevant tests unless the task
  explicitly does not require it. Report validation results and any checks you could not run.
- Review the diff before committing. Do not stage unrelated modified or untracked files;
  when asked to commit task changes, stage only the files belonging to that task.
- Create commits only when explicitly requested. Never push unless explicitly requested.
- Squash temporary or follow-up commits for one logical change only when explicitly requested;
  preserve the final file state and earlier unrelated history.

## C++ rules

The rules below apply to C++ code in `LeetCodeCpp`, not necessarily to other language projects.
Competitive-programming style is intentional here. These rules take precedence over
inconsistent older examples; do not expand a task into unrelated style cleanup.

### Layout and style

- Put solutions in the appropriate `problems/<category>/` directory. Normally use separate
  `ProblemName_<id>.h` and `.cpp` files with a matching class name and the problem method API.
- Use `#pragma once` in headers. Include the matching header in the solution `.cpp` and
  include the standard headers needed by each file. Reuse nodes and utilities from `common/`.
- Never put `using namespace std;` in a header; qualify standard-library names there.
- In solution `.cpp` files, use `using namespace std;` and avoid unnecessary `std::` prefixes.
  This is intentional even though library/application C++ style often recommends otherwise.
- Put opening braces for function definitions on a new line. Use four-space indentation,
  match nearby formatting, and aim for roughly 90-100 characters per line.
- Prefer concise, self-documenting code without sacrificing readability. Avoid comments that
  restate the code; add them only for non-obvious reasoning, invariants, constraints, or tricks.
  Keep longer algorithm explanations in `Docs/` when documentation is part of the task.
- Prefer `const` where appropriate and `size_t` for container indices where appropriate.
- Use `reserve()` when capacity is reasonably predictable and reserving it is useful.

### Algorithms

- Prefer the best practical asymptotic time and auxiliary-space complexity. Satisfy any
  complexity explicitly required by the problem, including constant-space requirements.
- Choose the simpler optimal or near-optimal approach. Use `set`, `map`, `priority_queue`,
  auxiliary vectors, and other standard containers when algorithmically appropriate. Avoid
  unnecessary containers or heap allocation when a simpler structure provides the same or
  better complexity and clarity.
- Use constant-space techniques when natural and appropriate. Do not overengineer for
  generality or obscure straightforward code for optimizations without a meaningful benefit.

### Tests and validation

- Extend the appropriate existing suite under `tests/suites/<category>/`. Do not create a
  separate test executable or framework for an individual problem.
- Add test-case types to `tests/test_cases/TestCases<Category>.h` in namespace `TestCases`.
  Include that category header in the suite; reuse assertions and utilities from
  `tests/framework/TestUtils.h` and `common/`.
- Follow the existing `bool` test functions in an anonymous namespace, using `REQUIRE_ASSERT`
  with the appropriate assertion helpers. Register the function with
  `TEST(id, "Problem title", function)` in the suite namespace's `getTests()`.
  `TestsRunner.cpp` already aggregates existing suites; new problems in them need no new runner.
- Meaningful coverage matters more than test count. Around 8-10 cases is a useful typical
  range, not a target. Include official examples when useful, structural edge cases, and
  delicate implementation paths. Choose cases based on what the algorithm can get wrong,
  not unusual numeric values alone.
- After C++ code changes, build the project and run the relevant tests. The existing runner
  runs all registered suites. Verify assertion results and suite completion, not just exit code.
- Windows only: the commands below use PowerShell and Visual Studio C++ Build Tools/MSVC.
  Run them from `LeetCodeCpp`. On other platforms or in other environments, inspect and use
  the repository's existing native build workflow instead of introducing a new one.

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\build.ps1 -Config Debug
if ($LASTEXITCODE -ne 0) { throw "C++ build failed." }
.\build\Debug\TestsRunner.exe
```

The build script discovers `.cpp` files recursively and writes generated output under `build/`.
Use the existing toolchain configuration; do not add machine-specific absolute paths.

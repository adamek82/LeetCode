import sqlite3
from dataclasses import dataclass
from pathlib import Path
from typing import List, Tuple, Optional


ROOT = Path(__file__).resolve().parent
PROBLEMS_DIR = ROOT / "problems"


@dataclass
class ProblemFiles:
    name: str
    dir: Path
    seed_sql: Path
    solution_sql: Path
    expected_tsv: Path


def read_text(path: Path) -> str:
    return path.read_text(encoding="utf-8")


def list_problems() -> List[ProblemFiles]:
    if not PROBLEMS_DIR.exists():
        raise RuntimeError(f"Missing directory: {PROBLEMS_DIR}")

    problems: List[ProblemFiles] = []
    for pdir in sorted([p for p in PROBLEMS_DIR.iterdir() if p.is_dir()]):
        seed = pdir / "seed.sql"
        sol = pdir / "solution.sql"
        exp = pdir / "expected.tsv"
        if seed.exists() and sol.exists() and exp.exists():
            problems.append(ProblemFiles(pdir.name, pdir, seed, sol, exp))
    return problems


def run_script(conn: sqlite3.Connection, sql: str) -> None:
    conn.executescript(sql)


def run_query(conn: sqlite3.Connection, sql: str) -> Tuple[List[str], List[Tuple]]:
    cur = conn.execute(sql)
    cols = [d[0] for d in cur.description] if cur.description else []
    rows = cur.fetchall()
    return cols, rows


def to_tsv(cols: List[str], rows: List[Tuple]) -> List[str]:
    # TSV with header row
    lines = ["\t".join(cols)]
    for r in rows:
        cells = []
        for v in r:
            if v is None:
                cells.append("NULL")
            else:
                cells.append(str(v))
        lines.append("\t".join(cells))
    return lines


def normalize_lines(text: str) -> List[str]:
    # Remove empty lines, normalize line endings, keep order
    lines = []
    for line in text.splitlines():
        line = line.rstrip()
        if line.strip() == "":
            continue
        lines.append(line)
    return lines


def compare_expected(got_lines: List[str], expected_text: str) -> Tuple[bool, List[str]]:
    expected_lines = normalize_lines(expected_text)
    ok = got_lines == expected_lines
    return ok, expected_lines


def run_one(problem: ProblemFiles) -> Tuple[bool, Optional[str]]:
    seed = read_text(problem.seed_sql)
    solution = read_text(problem.solution_sql)
    expected = read_text(problem.expected_tsv)

    conn = sqlite3.connect(":memory:")
    try:
        conn.execute("PRAGMA foreign_keys = ON;")
        run_script(conn, seed)

        cols, rows = run_query(conn, solution)
        got_lines = to_tsv(cols, rows)

        ok, expected_lines = compare_expected(got_lines, expected)

        if ok:
            return True, None

        # Build a small diff-like message
        msg = []
        msg.append("Expected TSV:")
        msg.extend(expected_lines)
        msg.append("Got TSV:")
        msg.extend(got_lines)
        return False, "\n".join(msg)

    finally:
        conn.close()


def main():
    problems = list_problems()
    if not problems:
        print(f"No problems found in: {PROBLEMS_DIR}")
        print("Each problem must contain: seed.sql, solution.sql, expected.tsv")
        return

    passed = 0
    failed = 0

    print(f"Running LeetCodeSql tests ({len(problems)} problems):")

    for prob in problems:
        ok, details = run_one(prob)
        if ok:
            passed += 1
            print(f"[{prob.name}] PASS")
        else:
            failed += 1
            print(f"[{prob.name}] FAIL")
            if details:
                print(details)
            print("-" * 60)

    print(f"Summary: PASS={passed}, FAIL={failed}, TOTAL={passed + failed}")


if __name__ == "__main__":
    main()

import sqlite3
from pathlib import Path

ROOT = Path(__file__).resolve().parent
PROBLEM_DIR = ROOT / "problems" / "0182_duplicate_emails"

SEED_SQL = PROBLEM_DIR / "seed.sql"
SOLUTION_SQL = PROBLEM_DIR / "solution.sql"
EXPECTED_TXT = PROBLEM_DIR / "expected.txt"


def read_text(path: Path) -> str:
    return path.read_text(encoding="utf-8")


def run_script(conn: sqlite3.Connection, sql: str) -> None:
    conn.executescript(sql)


def run_query(conn: sqlite3.Connection, sql: str):
    cur = conn.execute(sql)
    cols = [d[0] for d in cur.description] if cur.description else []
    rows = cur.fetchall()
    return cols, rows


def normalize_expected_lines(text: str):
    # expected.txt: jedna wartość na linię (np. email)
    # ignoruj puste linie i spacje na końcach
    return [line.strip() for line in text.splitlines() if line.strip()]


def extract_first_col_as_lines(rows):
    # dla tego zadania spodziewamy się 1 kolumny
    return [("" if r[0] is None else str(r[0])) for r in rows]


def main():
    seed = read_text(SEED_SQL)
    solution = read_text(SOLUTION_SQL)
    expected_lines = normalize_expected_lines(read_text(EXPECTED_TXT))

    conn = sqlite3.connect(":memory:")
    try:
        # sensowne ustawienia na start
        conn.execute("PRAGMA foreign_keys = ON;")
        run_script(conn, seed)

        cols, rows = run_query(conn, solution)

        got_lines = extract_first_col_as_lines(rows)

        ok = (got_lines == expected_lines)
        print(f"[0182] Duplicate Emails: {'PASS' if ok else 'FAIL'}")
        print(f"Columns: {cols}")
        print(f"Got: {got_lines}")
        print(f"Expected: {expected_lines}")

    finally:
        conn.close()


if __name__ == "__main__":
    main()

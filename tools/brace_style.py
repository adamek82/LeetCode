from pathlib import Path
import argparse
import re
import subprocess

ROOT = Path(__file__).resolve().parents[1] / "LeetCodeCpp"
EXTENSIONS = {".cpp", ".cc", ".cxx", ".h", ".hpp"}
EXCLUDED_DIRS = {
    "build", "bin", "generated", "cmakefiles", "external", "third_party", "vendor",
    "node_modules", "__pycache__",
}

CONTROL = {"if", "for", "while", "switch", "catch"}
SUFFIX_WORDS = ("const", "volatile", "override", "final")


def sanitize(text: str) -> str:
    """
    Replace comments, strings and character literals with spaces,
    preserving newlines and character positions.
    """
    out = list(text)

    i = 0
    state = "normal"

    while i < len(text):
        if state == "normal":
            if text[i] == "#" and not "".join(out[line_start(text, i):i]).strip():
                end = i
                while True:
                    end = text.find("\n", end)
                    if end == -1:
                        end = len(text)
                        break
                    continued = text[i:end].rstrip("\r \t").endswith("\\")
                    end += 1
                    if not continued:
                        break
                out[i:end] = [ch if ch in "\r\n" else " " for ch in text[i:end]]
                i = end
                continue

            if text.startswith("//", i):
                out[i] = out[i + 1] = " "
                i += 2
                state = "line_comment"
                continue

            if text.startswith("/*", i):
                out[i] = out[i + 1] = " "
                i += 2
                state = "block_comment"
                continue

            if text.startswith('R"', i):
                raw = re.match(r'R"([^ ()\\\t\v\f\r\n]{0,16})\(', text[i:])
                if raw:
                    delimiter = ")" + raw.group(1) + '"'
                    end = text.find(delimiter, i + raw.end())
                    end = len(text) if end == -1 else end + len(delimiter)
                    out[i:end] = [ch if ch in "\r\n" else " " for ch in text[i:end]]
                    i = end
                    continue

            # Apostrophes within numeric literals are digit separators, not quotes.
            if text[i].isdigit() and (
                i == 0 or not (text[i - 1].isalnum() or text[i - 1] == "_")
            ):
                number = re.match(r"[0-9][\w']*", text[i:])
                i += number.end()
                continue

            if text[i] == '"':
                out[i] = " "
                i += 1
                state = "string"
                continue

            if text[i] == "'":
                out[i] = " "
                i += 1
                state = "char"
                continue

        elif state == "line_comment":
            if text[i] == "\n":
                if not text[line_start(text, i):i].rstrip("\r \t").endswith("\\"):
                    state = "normal"
            else:
                out[i] = " "

        elif state == "block_comment":
            if text.startswith("*/", i):
                out[i] = out[i + 1] = " "
                i += 2
                state = "normal"
                continue

            if text[i] != "\n":
                out[i] = " "

        elif state in {"string", "char"}:
            delimiter = '"' if state == "string" else "'"

            if text[i] == "\\":
                out[i] = " "

                if i + 1 < len(text) and text[i + 1] != "\n":
                    out[i + 1] = " "
                    i += 2
                    continue

            elif text[i] == delimiter:
                out[i] = " "
                i += 1
                state = "normal"
                continue

            if text[i] != "\n":
                out[i] = " "

        i += 1

    return "".join(out)


def previous_nonspace(text: str, pos: int) -> int:
    pos -= 1

    while pos >= 0 and text[pos].isspace():
        pos -= 1

    return pos


def matching_open_paren(text: str, close_pos: int):
    depth = 1
    i = close_pos - 1

    while i >= 0:
        if text[i] == ")":
            depth += 1

        elif text[i] == "(":
            depth -= 1

            if depth == 0:
                return i

        i -= 1

    return None


def token_before(text: str, pos: int) -> str:
    i = pos - 1

    while i >= 0 and text[i].isspace():
        i -= 1

    end = i + 1

    while i >= 0 and (text[i].isalnum() or text[i] in "_~"):
        i -= 1

    return text[i + 1:end]


def line_start(text: str, pos: int) -> int:
    return text.rfind("\n", 0, pos) + 1


def is_word_at(text: str, pos: int, word: str) -> bool:
    if not text.startswith(word, pos):
        return False

    before_ok = (
        pos == 0
        or not (text[pos - 1].isalnum() or text[pos - 1] == "_")
    )

    end = pos + len(word)

    after_ok = (
        end == len(text)
        or not (text[end].isalnum() or text[end] == "_")
    )

    return before_ok and after_ok


def skip_ws(text: str, pos: int) -> int:
    while pos < len(text) and text[pos].isspace():
        pos += 1

    return pos


def skip_balanced_parens(text: str, pos: int):
    if pos >= len(text) or text[pos] != "(":
        return None

    depth = 1
    pos += 1

    while pos < len(text):
        if text[pos] == "(":
            depth += 1

        elif text[pos] == ")":
            depth -= 1

            if depth == 0:
                return pos + 1

        pos += 1

    return None


def valid_function_suffix(suffix: str) -> bool:
    """
    Accept common syntax between the parameter list and the function body:

        const
        volatile
        &
        &&
        noexcept
        noexcept(...)
        override
        final
        [[attributes]]
        -> trailing return type
        : constructor initializer list
    """
    pos = 0

    while True:
        pos = skip_ws(suffix, pos)

        if pos == len(suffix):
            return True

        if suffix.startswith("&&", pos):
            pos += 2
            continue

        if suffix[pos] == "&":
            pos += 1
            continue

        matched_word = False

        for word in SUFFIX_WORDS:
            if is_word_at(suffix, pos, word):
                pos += len(word)
                matched_word = True
                break

        if matched_word:
            continue

        if is_word_at(suffix, pos, "noexcept"):
            pos += len("noexcept")
            pos = skip_ws(suffix, pos)

            if pos < len(suffix) and suffix[pos] == "(":
                end = skip_balanced_parens(suffix, pos)

                if end is None:
                    return False

                pos = end

            continue

        if suffix.startswith("[[", pos):
            end = suffix.find("]]", pos + 2)

            if end == -1:
                return False

            pos = end + 2
            continue

        # Trailing return type:
        #
        #     auto foo() -> vector<int> {
        #
        if suffix.startswith("->", pos):
            return_type = suffix[pos + 2:].strip()
            return (
                re.fullmatch(r"[\w\s:*&,<>\[\]]+", return_type) is not None
                and not re.search(r"\brequires\b", return_type)
            )

        # Constructor initializer list:
        #
        #     Foo::Foo()
        #         : a(1), b(makeValue()) {
        #
        # A complete final initializer should end in ')' or '}'.
        # This also prevents x{1} itself from being mistaken for
        # the constructor body.
        if suffix[pos] == ":" and not suffix.startswith("::", pos):
            rest = suffix[pos + 1:].strip()

            return bool(rest) and rest[-1] in ")}"

        return False


def looks_like_operator(prefix: str) -> bool:
    """
    Match operator(), operator[], operator<<, operator==, etc.
    """
    return re.search(
        r"\boperator\s*(?:\(\)|\[\]|[^\w\s]+)\s*$",
        prefix
    ) is not None


def looks_like_function_declarator(
    text: str,
    open_paren: int,
    close_paren: int,
    brace: int
) -> bool:
    start = line_start(text, open_paren)

    prefix = text[start:open_paren].strip()
    suffix = text[close_paren + 1:brace]

    if re.search(
        r"\b(?:if|for|while|switch|catch|class|struct|namespace|enum|requires|"
        r"return|co_return|throw|new|delete)\b", prefix
    ):
        return False

    # operator[] has ']' immediately before its parameter list, which
    # otherwise looks superficially like a lambda capture.
    if looks_like_operator(prefix):
        return valid_function_suffix(suffix)

    token = token_before(text, open_paren)

    if token in CONTROL or token in {"decltype", "sizeof", "alignof", "alignas", "noexcept"}:
        return False

    # Lambda:
    #
    #     [&](...)
    #     [=](...)
    #     [](...)
    #
    prev = previous_nonspace(text, open_paren)

    if prev >= 0 and text[prev] == "]":
        return False

    # Typical macro invocation such as:
    #
    #     TEST(...)
    #
    if token and re.fullmatch(r"[A-Z_][A-Z0-9_]*", token):
        return False

    if not token:
        return False

    name_pos = prefix.rfind(token)

    if name_pos < 0:
        return False

    before_name = prefix[:name_pos].strip()

    # Strong signs that this '(' belongs to an expression rather than
    # to the actual function declarator.
    if any(ch in before_name for ch in "=();?[]{}"):
        return False

    # Constructor initializer continuation:
    #
    #     : member(...)
    #
    if before_name.startswith(":"):
        return False

    # Qualified member / constructor / destructor:
    #
    #     Foo::bar(...)
    #     Foo::Foo(...)
    #     Foo::~Foo(...)
    #
    if "::" in prefix:
        return valid_function_suffix(suffix)

    # Ordinary free/member function:
    #
    #     bool foo(...)
    #     static vector<int> bar(...)
    #
    if before_name:
        return valid_function_suffix(suffix)

    # Unqualified destructor inside a class:
    #
    #     ~Foo() {
    #
    if token.startswith("~"):
        return valid_function_suffix(suffix)

    # Unqualified inline constructor.
    #
    # Repository class names follow UpperCamelCase, which is a useful
    # conservative signal:
    #
    #     Foo() {
    #
    #     Node(int c) : count(c) {
    #
    if token[0].isupper():
        # Reject the second/subsequent entry of a multiline constructor
        # initializer list:
        #
        #     : first(...),
        #       second(...) {
        #
        prev_line_token = previous_nonspace(text, start)

        if (
            prev_line_token >= 0
            and text[prev_line_token] == ","
        ):
            return False

        return valid_function_suffix(suffix)

    return False


def find_function_parameter_list(text: str, brace: int):
    """
    Search backwards for the function parameter list, but never cross
    a statement/block boundary.

    This is essential for constructs such as:

        void foo()
        {
            for (...) {

    Once for(...) is rejected, the search must stop at the '{' of foo()
    instead of continuing backwards to foo().
    """
    pos = brace - 1
    attempts = 0

    while (
        pos >= 0
        and attempts < 32
        and brace - pos < 4000
    ):
        ch = text[pos]

        # Do not escape from the declaration / current statement.
        #
        # This prevents:
        #   for (...) {
        #   if (...) {
        #   while (...) {
        #   struct Foo {
        #   foo({ ... })
        #
        # from borrowing a parameter list from an earlier function.
        if ch in "{};":
            return None

        if ch != ")":
            pos -= 1
            continue

        open_paren = matching_open_paren(text, pos)

        if open_paren is None:
            return None

        attempts += 1

        if looks_like_function_declarator(
            text,
            open_paren,
            pos,
            brace
        ):
            return open_paren, pos

        pos = open_paren - 1

    return None


def empty_body_close(text: str, brace: int):
    """
    Return the position of '}' if this is an empty body on one line.

    Accept:

        {}
        {   }
    """
    pos = brace + 1

    while pos < len(text) and text[pos] in " \t":
        pos += 1

    if pos < len(text) and text[pos] == "}":
        return pos

    return None


def find_changes(text: str):
    clean = sanitize(text)
    changes = []

    for brace, ch in enumerate(clean):
        if ch != "{":
            continue

        prev = previous_nonspace(clean, brace)

        if prev < 0:
            continue

        # Already in desired style if '{' is on another physical line.
        between = text[prev + 1:brace]

        if "\n" in between or "\r" in between:
            continue

        # Only horizontal whitespace may separate the previous token
        # from the opening body brace.
        if between and not between.isspace():
            continue

        params = find_function_parameter_list(clean, brace)

        if params is None:
            continue

        open_paren, close_paren = params

        # Replace only whitespace immediately before '{'.
        start = prev + 1

        changes.append(
            (start, brace, open_paren, close_paren)
        )

    return changes


def apply_changes(text: str, changes):
    newline = "\r\n" if "\r\n" in text else "\n"

    for start, brace, open_paren, _ in reversed(changes):
        signature_line_begin = (
            text.rfind("\n", 0, open_paren) + 1
        )

        indent = re.match(
            r"[ \t]*",
            text[signature_line_begin:]
        ).group()

        empty_close = empty_body_close(text, brace)

        if empty_close is not None:
            text = (
                text[:start]
                + newline
                + indent
                + "{"
                + newline
                + indent
                + "}"
                + text[empty_close + 1:]
            )
        else:
            text = (
                text[:start]
                + newline
                + indent
                + text[brace:]
            )

    return text


def print_preview(path: Path, text: str, change):
    start, brace, open_paren, _ = change

    line_begin = text.rfind("\n", 0, brace) + 1

    line_end = text.find("\n", brace)

    if line_end == -1:
        line_end = len(text)

    old_line = text[line_begin:line_end].rstrip("\r")

    signature_line_begin = (
        text.rfind("\n", 0, open_paren) + 1
    )

    indent = re.match(
        r"[ \t]*",
        text[signature_line_begin:]
    ).group()

    line_no = text.count("\n", 0, brace) + 1

    before_brace = text[line_begin:start].rstrip()
    after_brace = text[brace + 1:line_end].rstrip("\r")

    print(f"{path}:{line_no}")
    print(f"- {old_line}")
    print(f"+ {before_brace}")

    empty_close = empty_body_close(text, brace)

    if empty_close is not None:
        tail = text[empty_close + 1:line_end].rstrip("\r")

        print(f"+ {indent}{{")
        print(f"+ {indent}}}{tail}")
    else:
        print(f"+ {indent}{{{after_brace}")

    print()


def read_file(path: Path) -> str:
    # newline="" is important: preserve CRLF vs LF exactly.
    with path.open(
        "r",
        encoding="utf-8",
        newline=""
    ) as f:
        return f.read()


def write_file(path: Path, text: str):
    with path.open(
        "w",
        encoding="utf-8",
        newline=""
    ) as f:
        f.write(text)


def source_files():
    result = subprocess.run(
        ["git", "-C", str(ROOT), "ls-files", "-z", "--",
         "TestsRunner.cpp", "common", "problems", "tests"],
        check=True, capture_output=True, encoding="utf-8"
    )

    for name in result.stdout.split("\0"):
        relative = Path(name)
        if relative.suffix not in EXTENSIONS:
            continue
        if any(
            part.lower() in EXCLUDED_DIRS
            or part.startswith(".")
            or part.lower().startswith(("build-", "cmake-build-"))
            for part in relative.parts[:-1]
        ):
            continue

        path = ROOT / relative
        if path.is_file() and path.resolve() == path.absolute():
            yield path


def main():
    parser = argparse.ArgumentParser(
        description="Preview function opening-brace changes in tracked LeetCodeCpp sources.",
        epilog="Uses syntax heuristics, not a full C++ parser. Review the preview before --apply. "
               "Requires Git; generated, untracked, and linked files are excluded."
    )

    parser.add_argument(
        "--apply",
        action="store_true",
        help="write the previewed changes; without this option, files are not modified"
    )

    args = parser.parse_args()

    if not ROOT.is_dir():
        parser.error(f"C++ project directory not found: {ROOT}")
    try:
        paths = list(source_files())
    except (OSError, subprocess.CalledProcessError) as error:
        parser.error(f"cannot list tracked C++ files with Git: {error}")

    total = 0

    for path in paths:
        text = read_file(path)
        changes = find_changes(text)

        if not changes:
            continue

        total += len(changes)

        if args.apply:
            write_file(
                path,
                apply_changes(text, changes)
            )
        else:
            for change in changes:
                print_preview(
                    path,
                    text,
                    change
                )

    print(f"Total candidates: {total}")


if __name__ == "__main__":
    main()

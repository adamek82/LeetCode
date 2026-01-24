#include "DecodeString_GoogleOnsite.h"
#include <stack>
#include <stdexcept>

/*────────────────────────────────────────────────────────────────────────────
  Decode string of the form      ab[cd]{2}def  →  abcdcddef

  ──────────────────────────────  Grammar  ───────────────────────────────────
    <expr>    ::= <text> | <expr><expr> | <segment>

    <segment> ::= '[' <body> ']' '{' <k> '}'         // repeat <body> k times
    <body>    ::= <expr>                             // may be nested
    <text>    ::= 1⁺ letters                         // plain characters
    <k>       ::= 1⁺ digits                          // positive integer

  ──────────────────────────────  High-level idea  ───────────────────────────
  Scan the input once and maintain two data structures:

  •  stack<string> strStack      –  the already-decoded prefix that appears
                                    **before** each currently open '['.
  •  string cur                  –  the substring we are building inside the
                                    innermost unmatched '[' … ']'.

  When we see
    '['   push current prefix, clear cur
    ']'   (just a delimiter – skip; the number comes next)
    '{'   read integer k, pop the matching prefix,
          cur ← prefix + repeat(cur, k)        // collapse this layer
    letter  append to cur

  Because an inner segment finishes (collapses) before its enclosing one,
  the method naturally handles arbitrary nesting.

  ──────────────────────────────  Complexity  ────────────────────────────────
  Each character is processed a constant number of times, so

        Time   O(n)
        Space  O(d)        (d = maximum nesting depth, ≤ n)

  This is asymptotically optimal: every algorithm must at least read the n
  input characters once.

  ──────────────────────────────  Correctness sketch  ────────────────────────
  Induction on the nesting depth of segments.

  •  Base case (depth 1): at the closing '}' we have  cur = <body>.  Repeating
     it k times and prefixing with the saved string yields exactly the decoded
     value for that segment.

  •  Inductive step: collapsing every inner segment (depth ≤ d) converts a
     depth d+1 instance into depth d, which is correctly decoded by the
     induction hypothesis.

  Therefore the algorithm produces the correct expansion for any well-formed
  input.                                                               ∎
──────────────────────────────────────────────────────────────────────────────*/
string DecodeString_GoogleOnsite::decode(const string &s)
{
    stack<string> strStack;   // prefixes before each '['
    string cur;               // text inside current [...] block

    for (size_t i = 0; i < s.size(); ) {
        char ch = s[i];

        if (ch == '[') {
            strStack.push(cur);
            cur.clear();
            ++i;
        } else if (ch == ']') {
            ++i;                  // nothing to do; wait for '{'
        } else if (ch == '{') {
            ++i;                  // skip '{'
            long long k = 0;
            while (i < s.size() && isdigit(s[i]))
                k = k * 10 + (s[i++] - '0');
            if (i == s.size() || s[i] != '}')
                throw invalid_argument("Malformed input");
            ++i;                  // skip '}'

            if (strStack.empty())
                throw invalid_argument("Malformed input");

            string base = strStack.top();
            strStack.pop();

            string repeated;
            repeated.reserve(cur.size() * k);
            for (long long t = 0; t < k; ++t) repeated += cur;

            cur = base + repeated;   // collapse this layer
        } else {                     // ordinary character
            cur += ch;
            ++i;
        }
    }

    if (!strStack.empty())
        throw invalid_argument("Unbalanced brackets");

    return cur;
}

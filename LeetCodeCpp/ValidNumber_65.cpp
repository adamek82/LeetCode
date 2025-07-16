#include "ValidNumber_65.h"

/*
 * One-pass DFA-style scan (O(n) time, O(1) space)
 * ------------------------------------------------
 * We walk the string left-to-right, flipping four booleans that encode the
 *   grammar’s state.  At every step we reject characters that violate the
 *   rules, so if the loop finishes the input must be valid.
 *
 *   ┌─────────────────────────────────────────────────────────┐
 *   │  FLAG                    MEANING                        │
 *   ├─────────────────────────────────────────────────────────┤
 *   │ seenDigit       at least one digit before an optional   │
 *   │                 exponent has appeared                   │
 *   │ seenDot         a decimal point has already been met    │
 *   │ seenExp         an exponent marker ‘e’/‘E’ has appeared │
 *   │ digitAfterExp   at least one digit has followed the     │
 *   │                 exponent (only relevant when seenExp)   │
 *   └─────────────────────────────────────────────────────────┘
 *
 * State-transition rules enforced in the loop
 * ------------------------------------------
 * 1. Digit:                always allowed; sets seenDigit and, if in the
 *                          exponent part, sets digitAfterExp.
 * 2. Dot ‘.’:              allowed only once and only before any exponent.
 * 3. Exponent ‘e’/‘E’:     allowed once, must follow a digit, and cannot
 *                          be the last character; resets digitAfterExp=false.
 * 4. Sign ‘+’/‘-’:         allowed only at the beginning of the string or
 *                          immediately after an exponent.
 * 5. Anything else:        invalid → early rejection.
 *
 * Loop invariants
 * ---------------
 * • Before seeing an exponent, at least one of {seenDigit, seenDot} can still
 *   be false; after the exponent, digitAfterExp must eventually become true.
 * • seenDot and seenExp are monotone: once they become true they never reset.
 *
 * Final acceptance test
 * ---------------------
 * The string is a valid number iff
 *       seenDigit               // some digit in the base    (integer/decimal)
 *   && digitAfterExp            // if exponent present, it   (integer)
 *                               // has at least one digit.
 *
 * Complexity
 * ----------
 * • Time:  O(n) — each character examined once.
 * • Space: O(1) — four booleans.
 *
 * This directly encodes the formal grammar given in the problem statement,
 * guaranteeing correctness while remaining simple and efficient.
 */

bool ValidNumber_65::isNumber(string s)
{
    bool seenDigit = false;     // any digit before an optional exponent
    bool seenDot   = false;     // decimal point already met?
    bool seenExp   = false;     // exponent character already met?
    bool digitAfterExp = true;  // at least one digit after 'e' / 'E'

    for (int i = 0; i < static_cast<int>(s.size()); ++i) {
        char c = s[i];

        if (isdigit(c)) {
            seenDigit = true;
            if (seenExp) digitAfterExp = true;      // digit belongs to exponent part
        }
        else if (c == '.') {
            // dot allowed only once and only before exponent
            if (seenDot || seenExp) return false;
            seenDot = true;
        }
        else if (c == 'e' || c == 'E') {
            // exponent must appear once, after at least one digit, and cannot be last
            if (seenExp || !seenDigit) return false;
            seenExp = true;
            digitAfterExp = false;                  // reset – now we must see digits
        }
        else if (c == '+' || c == '-') {
            // sign allowed only at start or immediately after an exponent
            if (i == 0) continue;
            if (s[i - 1] == 'e' || s[i - 1] == 'E') continue;
            return false;
        }
        else {
            return false;                           // any other character is invalid
        }
    }
    // valid when we saw a digit before end and, if exponent exists, digits after it
    return seenDigit && digitAfterExp;
}
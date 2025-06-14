#include "AddBinary_67.h"
#include <algorithm>      // for reverse

using namespace std;

/*
 * Add Binary  — Back-to-Front Addition  — Correctness Sketch
 *
 * Pointers i ← a.size()-1, j ← b.size()-1, carry ← 0.
 * Loop while i ≥0 || j ≥0 || carry:
 *   sum = carry + (i≥0 ? a[i--]-'0' : 0) + (j≥0 ? b[j--]-'0' : 0);
 *   push_back('0'+(sum&1));   carry = sum>>1;
 * Reverse the built string to obtain MSB→LSB order.
 *
 * Complexity
 *   – Time:  O(max(|a|,|b|))
 *   – Space: O(max(|a|,|b|)) for the result string
 */
string AddBinary_67::addBinary(string a, string b)
{
    string res;
    int i = static_cast<int>(a.size()) - 1;
    int j = static_cast<int>(b.size()) - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        res.push_back(char('0' + (sum & 1)));
        carry = sum >> 1;
    }
    reverse(res.begin(), res.end());
    return res;
}

#include "FizzBuzz_412.h"

vector<string> FizzBuzz_412::fizzBuzz(int n)
{
    vector<string> ans;
    ans.reserve(n);

    for (int i=1; i<=n; ++i) {
        bool fizz = (i % 3 == 0);
        bool buzz = (i % 5 == 0);
        if (fizz && buzz)
            ans.push_back("FizzBuzz");
        else if (fizz && !buzz)
            ans.push_back("Fizz");
        else if (!fizz && buzz)
            ans.push_back("Buzz");
        else
            ans.push_back(to_string(i));
    }

    return ans;
}
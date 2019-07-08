/*
38. Count and Say       *EASY*

The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.



Example 1:

Input: 1
Output: "1"
Example 2:

Input: 4
Output: "1211"
*/

#include <iostream>
#include <string>

using namespace std;

string NextNumber (string s) {
    string result;
    for (int i(0); i < s.size(); ++i) {
        int count = 1;
        while (i + 1 < s.size() && s[i] == s[i + 1]) {
            ++i, ++count;
        }
        result += to_string(count) + s[i];
    }
    return result;
}

string CountAndSay (int n) {
    string s = "1";
    for (int i(1); i < n; ++i) {
        s = NextNumber(s);
    }
    return s;
}

int main() {
    cout << CountAndSay(4);
}

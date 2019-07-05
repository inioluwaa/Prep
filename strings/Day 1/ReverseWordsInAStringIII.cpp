/*

557. Reverse Words in a String III  *EASY*

Given a string, you need to reverse the order of characters in each word within a sentence
while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.

*/

#include <iostream>
#include <string>

using namespace std;

void ReverseWordsInAString (string &s) {
    int start = 0, end;
    while ((end = s.find_first_of(' ', start)) != string::npos) {
        reverse(s.begin() + start, s.begin() + end);
        start = end + 1;
    }
    reverse(s.begin() + start, s.end());
}
int main() {
    string s = "Let's take LeetCode contest";
    ReverseWordsInAString(s);
    cout << s;
}



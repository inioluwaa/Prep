/*

Daily Coding Problem: Problem #114      *HARD*

Given a string and a set of delimiters, reverse the words in the string while maintaining the
relative order of the delimiters. For example, given "hello/world:here", return "here/world:hello".

Follow-up: Does your solution work for the following cases: "hello/world:here/", "hello//world:here".

*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

string Reverse (const string& s) {
    stack<string> words{};
    string word;
    int i = 0;
    while (i < s.size()) {
        int k = i;
        while (isalpha(s[k])) {
            k++;
        }
        if (k - i > 0) {
            word = s.substr(i, k-i);
            words.push(word);
            i = k;
        }
        else
            i++;
    }
    string result;
    int l = 0;
    while (l < s.size()) {
        if (!isalpha(s[l])) {
            string stacker = words.top();
            if (l >= 1 && isalpha(s[l - 1])) {
                result += stacker;
                words.pop();
            }
            result.push_back(s[l]);
        }
        l++;
    }
    if (!words.empty()) {
        result += words.top();
    }
    return result;
}

int main() {
    string s = "hello/world:here";
    string r = "/hello//world:here/house";
    string p = Reverse(r);
    cout << p;
}

#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>

using namespace std;

bool CheckKey (unordered_set<char> T, char key) {
    return !(T.find(key) == T.end());
}

string ReverseVowels (const string &s) {
    string result;
    unordered_set<char> T = {'a', 'e', 'i', 'o', 'u'};
    stack<char> vowels{};

    for (char i : s) {
        if (CheckKey(T, tolower(i))) {
            vowels.push(i);
        }
    }
    if (vowels.empty()) return s;

    for (int i(0); i < s.size(); ++i) {
        if (CheckKey(T, tolower(s[i]))) {
            result.push_back(vowels.top());
            vowels.pop();
        }
        else {
            result.push_back(s[i]);
        }
    }
    return result;
}

int main() {
    string stuff = "Hello";
    cout << ReverseVowels(stuff);
}
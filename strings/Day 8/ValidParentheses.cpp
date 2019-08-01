#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

bool MapContains (unordered_map<char, char> T, char key) {
    return !(T.find(key) == T.end());
}

bool IsValidBracket (const string &s) {
    stack<char> symbols{};
    unordered_map<char, char> T{{'(', ')'},
                                {'[', ']'},
                                {'{', '}'}
    };

    for (int i(0); i < s.size(); ++i) {
        if (MapContains(T, s[i])) {
            symbols.push(s[i]);
        }
        else {
            if (symbols.empty()) return false;
            if (s[i] == T[symbols.top()]) symbols.pop();
            else return false;
        }
    }
    return symbols.empty();
}

bool IsValidFast (const string &s) {
    stack<char> symbol{};
    for (char i : s) {
        if (i == '(' || i == '{' || i == '[') symbol.push(i);
        else {
            if (symbol.empty()) return false;
            if ((i == ')' && symbol.top() != '(') ||
                (i == '}' && symbol.top() != '{') ||
                (i == ']' && symbol.top() != '[')) {
                return false;
            }
            symbol.pop();
        }
    }
    return symbol.empty();
}
int main() {
    string s = "(])";
    cout << IsValidBracket(s);
}
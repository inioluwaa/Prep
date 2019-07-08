#include <iostream>
#include <string>
#include <stack>

using namespace std;

// Using Stacks
string ReverseOnlyLetters (string S) {
    stack<char> popper{};
    for (char i : S) {
        if (isalpha(i)) {
            popper.push(i);
        }
    }
    string result;
    int j = 0;
    while (j < S.size()) {
        if (isalpha(S[j])) {
            result.push_back(popper.top());
            popper.pop();
            j++;
        }
        else {
            result.push_back(S[j]);
            j++;
        }
    }
    return result;
}

int main() {
    string S = "Test1ng-Leet=code-Q!";
    cout << ReverseOnlyLetters(S);
}

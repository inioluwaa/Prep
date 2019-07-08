#include <iostream>
#include <string>
#include <vector>

using namespace std;


string ReverseOnlyLetters (string S) {
    string result = S;
    int i = S.size() - 1, j = 0;
    while (i >= 0 && j < S.size()) {
        if (isalpha(S[i]) && isalpha(S[j])) {
            result[j] = S[i];
            j++;
            i--;
        }
        else if (!isalpha(S[i])) {
            i--;
        }
        else {
            j++;
        }
    }
    return result;
}

int main() {
    string S = "Test1ng-Leet=code-Q!";
    cout << ReverseOnlyLetters(S);
}

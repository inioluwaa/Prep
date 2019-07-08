/*

917. Reverse Only Letters       *EASY*

Given a string S, return the "reversed" string where all characters
that are not a letter stay in the same place, and all letters reverse their positions.

Example 1:

Input: "ab-cd"
Output: "dc-ba"
Example 2:

Input: "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"
Example 3:

Input: "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"
*/

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



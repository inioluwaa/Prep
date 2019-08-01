#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool DetectCapitalUse (string &word) {
    vector<bool> checker{};
    for (int i(0); i < word.size(); ++i) {
        if (isupper(word[i]))
            checker.push_back(true);
        else
            checker.push_back(false);
    }
    int i = 1;
    while (i < checker.size()) {
        if (checker[0] == false) {
            if (checker[i] == true) return false;
        }
        else if (i < checker.size() - 1 && checker[0] == true && checker[1] == true) {
            if (checker[i + 1] == false) return false;
        }
        else if (i < checker.size() - 1 && checker[0] == true && checker[1] == false) {
            if (checker[i + 1] == true) return false;
        }
        i++;
    }
    return true;
}

bool DetectCapitalUse2 (string word) {
    for (int i(1); i < word.size(); ++i) {
        if (islower(word[0])) {
            if (isupper(word[i])) return false;
        }
        else if (i < word.size() - 1 && isupper(word[0]) && isupper(word[1])) {
            if (islower(word[i + 1])) return false;
        }
        else if (i < word.size() - 1 && isupper(word[0]) && islower(word[1])) {
            if (isupper(word[i + 1])) return false;
        }
    }
    return true;
}

int main() {
    string s = "usa";
    cout << DetectCapitalUse2(s);
}
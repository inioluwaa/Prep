#include <iostream>
#include <string>
#include <vector>

using namespace std;

string PressAForCapslock (string s) {
    string result;
    bool caps = false;
    for (int i(0); i < s.size(); ++i) {
        if (s[i] == 'a' || s[i] == 'A') {
            caps = !caps;
        }
        else if (caps) {
            result.push_back(toupper(s[i]));
        }
        else {
            result.push_back(s[i]);
        }
    }
    return result;
}

int main() {
    string s = "My keyboard is broakenParr";
    cout << PressAForCapslock(s);
}
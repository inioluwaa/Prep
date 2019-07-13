/*
925. Long Pressed Name      *EASY*
Your friend is typing his name into a keyboard.  Sometimes, when typing a character c,
the key might get long pressed, and the character will be typed 1 or more times.

You examine the typed characters of the keyboard.
Return True if it is possible that it was your friends name,
with some characters (possibly none) being long pressed.

Example 1:

Input: name = "alex", typed = "aaleex"
Output: true
Explanation: 'a' and 'e' in 'alex' were long pressed.
Example 2:

Input: name = "saeed", typed = "ssaaedd"
Output: false
Explanation: 'e' must have been pressed twice, but it wasn't in the typed output.
Example 3:

Input: name = "leelee", typed = "lleeelee"
Output: true
Example 4:

Input: name = "laiden", typed = "laiden"
Output: true
Explanation: It's not necessary to long press any character.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*bool IsLongPressedName (const string &name, const string &typed) {
    if (typed.size() < name.size()) return false;
    int j = 0;
    for (int i(0); i < name.size(); ++i) {
        if (typed[j] != name[i]) {
            if (j == 0 || typed[j - 1] != typed[j]) return false;
            char curr_elem = typed[j];
            while (j < typed.size() && typed[j] == curr_elem)
                j++;
            if (j == typed.size() || typed[j] != name[i]) return false;
        }
        j++;
    }
    return true;
}*/

bool IsLongPressedName (const string &name, const string &typed) {
    if (typed.size() < name.size()) return false;
    int i = 0, j = 0;
    while (i < name.size()) {
        if (typed[j] != name[i]) {
            if (j == 0 || typed[j - 1] != typed[j]) return false;
            char curr_elem = typed[j];
            while (j < typed.size() && typed[j] == curr_elem)
                j++;
            if (j == typed.size() && typed[j] != name[i]) return false;
        }
        j++;
        i++;
    }
    return true;
}

int main() {
    string name = "alexi";
    string typed = "aaleexi";
    cout << IsLongPressedName(name, typed);
}
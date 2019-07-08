#include <iostream>
#include <string>

using namespace std;

string NextNumber (string s) {
    string result;
    for (int i(0); i < s.size(); ++i) {
        int count = 1;
        while (i + 1 < s.size() && s[i] == s[i + 1]) {
            ++i, ++count;
        }
        result += to_string(count) + s[i];
    }
    return result;
}

string CountAndSay (int n) {
    string s = "1";
    for (int i(1); i < n; ++i) {
        s = NextNumber(s);
    }
    return s;
}

int main() {
    cout << CountAndSay(4);
}

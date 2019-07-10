#include <iostream>
#include <string>
#include <stack>

using namespace std;

void Reverse (const string& s) {
    stack<string> words{};
    string word;
    int start = 0, i = 0;
    while(i < s.size()) {
        if (isalpha(s[start]) && !isalpha(s[i])) {
            word = s.substr(start, i - start);
            words.push(word);
        }
        start = i + 1;
        i++;
    }
    word = s.substr(start, s.size() - 1 - start);
    words.push(word);

    while (!word.empty()) {
        cout << words.top() << endl;
        words.pop();
    }
}

int main() {
    string s = "hello/world:here";
    string r = "hello/world:here/house";
    Reverse(s);
}
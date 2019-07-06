#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

bool CheckKey(unordered_map<char, char> T, char key) {
    return !(T.find(key) == T.end());
}

bool Match(string word, string pattern) {
    unordered_map<char, char> Match1{};
    unordered_map<char, char> Match2{};

    for (int i(0); i < word.size(); ++i) {
        char w = word[i];
        char p = pattern[i];
        if (!CheckKey(Match1, w))
            Match1.insert({w, p});
        if (!CheckKey(Match2, p))
            Match2.insert({p, w});
        if (Match1.at(w) != p || Match2.at(p) != w) return false;
    }
    return true;
}
vector<string> FindAndReplacePattern(vector<string> &words, string pattern) {
    vector<string> result;
    for (const string& word : words) {
        if (Match(word, pattern)) result.push_back(word);
    }
    return result;
}

int main() {
    vector<string> v = {"abc","deq","mee","aqq","dkd","ccc"};
    string target = "abb";

    vector<string> answer = FindAndReplacePattern(v, target);
    for (auto i : answer)
        cout << i << " ";
}
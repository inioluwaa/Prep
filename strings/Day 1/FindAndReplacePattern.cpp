/*
890. Find and Replace Pattern   *MEDIUM*

You have a list of words and a pattern, and you want to know which words in words matches the pattern.

A word matches the pattern if there exists a permutation of letters p so that
after replacing every letter x in the pattern with p(x), we get the desired word.

(Recall that a permutation of letters is a bijection from letters to letters:
every letter maps to another letter, and no two letters map to the same letter.)

Return a list of the words in words that match the given pattern.

You may return the answer in any order.

Example 1:

Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]

Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}.
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation,
since a and b map to the same letter.
*/

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
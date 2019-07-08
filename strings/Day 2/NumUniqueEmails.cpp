/*
929. Unique Email Addresses     *EASY*
Every email consists of a local name and a domain name, separated by the @ sign.

For example, in alice@leetcode.com, alice is the local name, and leetcode.com is the domain name.

Besides lowercase letters, these emails may contain '.'s or '+'s.

If you add periods ('.') between some characters in the local name part of an email address,
mail sent there will be forwarded to the same address without dots in the local name.

For example, "alice.z@leetcode.com" and "alicez@leetcode.com" forward to the same email address.
(Note that this rule does not apply for domain names.)

If you add a plus ('+') in the local name, everything after the first plus sign will be ignored.
This allows certain emails to be filtered, for example m.y+name@email.com will be forwarded to my@email.com.
(Again, this rule does not apply for domain names.)

It is possible to use both of these rules at the same time.

Given a list of emails, we send one email to each address in the list.
How many different addresses actually receive mails?

Example 1:

Input: ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
Output: 2
Explanation: "testemail@leetcode.com" and "testemail@lee.tcode.com" actually receive mails
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int ReturnIndex (const string& s, char sym) {
    for (int i(0); i < s.size(); ++i) {
        if (s[i] == sym) {
            return i;
        }
    }
    return -1;
}

bool CheckElement (const string &s, char element) {
    return (s.find(element) != string::npos);
}

int NumUniqueEmails (vector<string> &emails) {
    unordered_set<string> seen{};
    for (const string& email : emails) {
        int i = ReturnIndex(email, '@');
        string local = email.substr(0, i);
        string domain = email.substr(i);
        if (CheckElement(local, '+')) {
            local = local.substr(0, ReturnIndex(local, '+'));
        }
        local.erase(remove(local.begin(), local.end(), '.'), local.end());
        seen.insert(local + domain);
    }
    return seen.size();
}
int main() {
    vector<string> v = {"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"};
    vector<string> u = {"test.email+alex@leetcode.com","test.email.leet+alex@code.com"};
    vector<string> w = {"a@leetcode.com","b@leetcode.com","c@leetcode.com"};
    int val = NumUniqueEmails(w);
    cout << val;
}

/*
344. Reverse String     *EASY*
Write a function that reverses a string. The input string is given as an array of characters char[].

Do not allocate extra space for another array,
you must do this by modifying the input array in-place with O(1) extra memory.

You may assume all the characters consist of printable ascii characters.



Example 1:

Input: ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void ReverseString (vector<char> &v) {
    int left = 0, right = v.size() - 1;
    while (left < right) {
        swap(v[left++], v[right--]);
    }
}
int main() {
    vector<char> v = {'H','a','n','n','a','h'};
    ReverseString(v);
    for (auto i : v)
        cout << i << " ";
}
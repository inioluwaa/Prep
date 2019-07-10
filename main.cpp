#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*string PressAForCapslock (string s) {
    string result;
    bool caps = false;
    for (int i(0); i < s.size(); ++i) {
        if (s[i] == 'a' || s[i] == 'A') {
            caps = !caps;
            i++;
        }
        if (caps) {
            s[i] = toupper(s[i]);
        }
        else {
            s[i] = tolower(s[i]);
        }
    }
    return s;
}*/

int FindPartition (vector<int> arr) {
    for (int i(0); i < arr.size(); ++i) {
        if (arr[i] >= 0) return i;
    }
    return -1;
}

vector<int> SquareSortedMatrix (vector<int> &arr) {
    vector<int> result(arr.size());
    int partition = FindPartition(arr);
    for (int i(0); i < arr.size(); ++i) {
        arr[i] = pow(arr[i], 2);
    }
    int a = partition - 1, b = partition;
    int i = 0;
    while (a >= 0 && b < arr.size()) {
        if (arr[a] <= arr[b]) {
            result[i] = arr[a];
            a--;
        }
        else {
            result[i] = arr[b];
            b++;
        }
        i++;
    }
    while (a >= 0) {
        result[i] = arr[a];
        a--;
        i++;
    }
    while (b < arr.size()) {
        result[i] = arr[b];
        b++;
        i++;
    }
    return result;
}

int main() {
    /*string s = "My keyboard is broaken";
    cout << PressAForCapslock(s);*/
    vector<int> T = {-9, -2, 0, 2, 3};
    vector<int> P = SquareSortedMatrix(T);
    for (auto i : P)
        cout << i << " ";
}
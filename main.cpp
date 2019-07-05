#include <iostream>
#include <string>

using namespace std;

bool JudgeCircle (const string& moves) {
    int count_right = 0, count_up = 0;
    for (char move : moves) {
        if (move == 'R') count_right++;
        else if (move == 'L') count_right--;
        else if (move == 'U') count_up++;
        else if (move == 'D') count_up--;
        else {
            return false;
        }
    }

    return (count_right == 0 && count_up == 0);
}
int main() {
    string moves = "UD";
    cout << JudgeCircle(moves);
}
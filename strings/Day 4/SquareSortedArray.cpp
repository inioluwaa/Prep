/*
Given a soted list of integers, square the element and the given output in sorted order.

For example, given [-9, -2, 0, 2, 3], return [0, 4, 4, 9, 81]
*/

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
    vector<int> T = {-9, -2, 0, 2, 3};
    vector<int> P = SquareSortedMatrix(T);
    for (auto i : P)
        cout << i << " ";
}
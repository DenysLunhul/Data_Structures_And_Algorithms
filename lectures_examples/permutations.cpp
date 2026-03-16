#include <iostream>
#include <vector>
using namespace std;

void permutations(vector<int>& arr, int step) {
    //Time Complexity - n * n!
    int n = arr.size();
    if (step == n) {
        for (int i = 0 ; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = step ; i < n; i++) {
        swap(arr[i], arr[step]);
        permutations(arr, step + 1);
        swap(arr[i], arr[step]);
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    permutations(arr, 0);
    return 0;
}

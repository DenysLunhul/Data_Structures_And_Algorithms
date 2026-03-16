#include <iostream>
#include <vector>
using namespace std;


string toBinary(int n) {
    string res = "";
    while (n > 0) {
        res = to_string(n % 2) + res;
        n /= 2;
    }
    return res;
}


int main() {
    int n;
    cin >> n;
    int target_sum;
    cin >> target_sum;
    vector<int> arr(n, 0);
    for (int i = 0 ; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < (1 << n); i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                sum += arr[j];
            }
        }
        if (sum == target_sum) {
            cout << toBinary(i) << endl;
        }
    }
    return 0;
}
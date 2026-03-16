#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> s = arr;
    for (int i = 1 ; i < n; i++) {
        s[i] = s[i - 1] + arr[i];
    }
    int r, l;
    cin >> l >> r;
    int summa = s[r];
    if (l > 0) {
        summa -= s[l - 1];
    }
    cout << summa;
    return 0;
}
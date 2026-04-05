#include  <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> arr(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    long long target;
    cin >> target;

    int left = 0;
    int right = n - 1;
    int mid;
    while (left < right) {
        mid = left + (right - left) / 2;
        if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }
    if (arr[left] == target) {
        cout << left;
    }
    else {
        cout << -1;
    }
    return 0;
}
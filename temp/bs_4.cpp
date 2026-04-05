#include <bits/stdc++.h>
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

    long long first;
    long long last;

    long long left = 0;
    long long right = n - 1;
    long long mid;
    while (left < right) {
        mid = left + (right - left) / 2;
        if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }
    first = left;


    left= 0;
    right = n - 1;
    while (left < right) {
        mid = left + (right - left) / 2;
        if (arr[mid] > target) {
            right = mid - 1;
        }        
        else {
            left = mid;
        }
    }
}

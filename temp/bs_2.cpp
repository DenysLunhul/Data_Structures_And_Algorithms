#include <bits/stdc++.h>
using namespace std;

long long f(vector<long long>& ropes, long long mid) {
    long long res = 0;
    for (long long r : ropes) {
        res += r / mid;
    }
    return res;
}

int main() {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> ropes(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> ropes[i];
    }

    long long left = 1;
    long long right = 100000000000;
    long long mid;
    while (left < right) {
        mid = left + (right - left) / 2;
        if (f(ropes, mid) >= k) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }
    if (f(ropes, left) >= k) {
        cout << left;
    }
    else {
        cout << left - 1;
    }
    return 0;
}
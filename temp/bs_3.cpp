#include <bits/stdc++.h>
using namespace std;


bool f(vector<long long>& rooms, long long x, long long n) {
    for (long long r : rooms) {
        if (r <= x) {
            n -= r;
        }
        else{
            n -= x;
        }
    }
    return n <= 0;
}


int main() {
    long long n, m;
    cin >> n >> m;
    long long total = 0;
    vector<long long> rooms(m, 0);
    for (int i = 0; i < m; i++) {
        cin >> rooms[i];
        total += rooms[i];
    }
    if (total < n) {
        cout << -1;
        return 0;
    }
    long long left = 1;
    long long right = 10000000000;
    long long mid;

    while (left < right) {
        mid = left + (right - left) / 2;
        if (!f(rooms, mid, n)) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }
    cout << left;
    return 0;
}
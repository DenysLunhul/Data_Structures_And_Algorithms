#include <iostream>
#include <cmath>
using namespace std;

long long rebuild(long long x1,long long x2,long long a,long long b,long long c, long long n) {
    for (long long i = 0; i < n - 2; i++) {
        long long x3 = a * x2 + b * x1 + c;
        if (abs(x3) > 1e7) return x3;
        x1 = x2;
        x2 = x3;
    }
    return x2;
}

int main() {
    long long a, b, c, n, x1, xn;
    cin >> a >> b >> c >> n >> x1 >> xn;

    if (n == 2) {
        cout << xn;
        return 0;
    }
    long long left = -1e7;
    long long right = 1e7;
    while (right - left > 1) {
        long long mid = (right + left) / 2;
        if (rebuild(x1, mid, a, b, c, n) > xn) {
            right = mid;
        }
        else {
            left = mid;
        }
    }
    if (rebuild(x1, left, a, b, c, n) == xn) {
        cout << left;
    } else {
        cout << right;
    }
    return 0;
}
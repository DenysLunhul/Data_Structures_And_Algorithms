#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

long double f(long double x) {
    return sin(4*x) + sin(sqrt(7)*x);
}

bool check(long double x, long double y) {
    return f(x) > y;
}

int main() {
    long double y;
    cin >> y;
    long double left = 0;
    long double right = 0;
    if (y > 0) {
        for (long long i = 1;;i++) {
            right = M_PI/8 + i * M_PI/2;
            if (check(right, y)) {
                break;
            }
        }
    }
    else {
        for (long long i = 1;;i++) {
            left = -M_PI/8 - i * M_PI/2;
            if (!check(left, y)) {
                break;
            }
        }
    }
    long double mid;
    for (int i = 0; i < 100; i++) {
        mid = left + (right - left) / 2;
        if (check(mid, y)) {
            right = mid;
        }
        else {
            left = mid;
        }
    }
    cout << fixed << setprecision(15) << left;
    return 0;
}
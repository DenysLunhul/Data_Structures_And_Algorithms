#include <iostream>
#include <vector>
using namespace std;

bool check(const vector<long long>& cars, long long time, long long k) {
    vector<bool> passed(cars.size(), false);
    int ptr = 0;
    for (long long i = 0; i < k; i++) {
        long long temp = time;
        while (temp > 0 and ptr < cars.size()) {
            if (temp > cars[ptr]){temp -= cars[ptr]; passed[ptr] = true;}
            else{temp = 0; passed[ptr] = true;}
            ptr++;
        }
    }
    return passed[passed.size() - 1];
}

int main() {
    long long n, k;
    cin >> n >> k;
    vector<long long> cars(n, 0);
    for (long long i = 0; i < n; i++) {
        cin >> cars[i];
    }
    long long left = 0;
    long long right = 1e12;
    while (right - left > 1) {
        long long mid = (right + left) / 2;
        if (check(cars, mid, k)) {
            right = mid;
        }
        else {
            left = mid;
        }
    }
    if (check(cars, left, k)) {cout << left;}
    else {cout << right << endl;}
    return 0;
}

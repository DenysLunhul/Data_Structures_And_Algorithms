#include  <iostream>
#include <vector>
using namespace std;

long long check(const vector<long long>& grades, long long n, long long k, long long x) {
    long long sum = 0;
    for (long long i = 0; i < n; i++) {
        long long val = grades[i] - x * (i + 1);
        if (val > 0) {
            if (val > 1e12) val = 1e12;
            sum += val;
            if (sum > 1e18) sum = 1e18;
        }
    }
    return sum;
}

int main() {
    long long n, k;
    cin >> n >> k;
    vector<long long> grades(n, 0);
    for (long long i = 0; i < n; i++) {
        cin >> grades[i];
    }
    long long left = -10000000000000;
    long long right = 10000000000000;
    long long answer = left;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (check(grades, n, k, mid) >= k) {
            answer = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    cout << answer << " " << check(grades, n, k, answer);
    return 0;
}
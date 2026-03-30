// 7 10 2 2 8 1 1 1 7
// 5 5 6 7 10 9 8
#include <iostream>
#include <vector>
using namespace std;

int main() {
    unsigned long long n, x;
    cin >> n >> x;
    vector<unsigned long long> segs(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> segs[i];
    }
    long long l = 0;
    long long sum = 0;
    long long max_len = -1;
    for (long long r = 0; r < n; r++) {
        sum += segs[r];
        while (sum > x) {
            sum -= segs[l];
            l++;
        }
        if (r - l + 1 > max_len) {
            max_len = r - l + 1;
        }
    }
    if (max_len == 0) {
        cout << -1;
    }
    else{
        cout << max_len;
    }
    return 0;
}
#include <iostream>
#include <map>
#include <numeric>
#include <cmath>
#include <algorithm>

using namespace std;


long long gcd(long long a, long long b) {
    a = abs(a);
    b = abs(b);
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    long long x, y;
    cin >> x >> y;
    int n;
    cin >> n;
    map<pair<long long, long long>, int> ray_cnt;
    int max_k = 0;
    for (int i = 0; i < n; ++i) {
        long long px, py;
        cin >> px >> py;
        long long dx = px - x;
        long long dy = py - y;
        long long temp = gcd(abs(dx), abs(dy));
        dx /= temp;
        dy /= temp;
        ray_cnt[{dx, dy}]++;
        max_k = max(max_k, ray_cnt[{dx, dy}]);
    }
    cout << max_k - 1;
    return 0;
}
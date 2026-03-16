#include <iostream>
#include <vector>
using namespace std;

long long solve(int n, vector<int>& memo) {
    if (n <= 3) return 1;
    if (memo[n] != 0) {
        return memo[n];
    }
    long long total = 0;
    for (int k = 2; k <= n - 1; k++) {
        total += solve(k, memo) * solve(n - k + 1, memo);
    }
    memo[n] = total;
    return total;
}

int main() {
    int n;
    cin >> n;
    vector<int> memo(n + 1, 0);
    cout << solve(n, memo);
    return 0;
}
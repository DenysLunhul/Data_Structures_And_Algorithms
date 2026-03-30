#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define INF 100000000000000000

int main() {
    long long n, k;
    cin >> n >> k;
    vector<long long> nums(n, 0);
    for (long long i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    vector<long long> d(n - 1, 0);
    for (long long i = 1; i < n; i++) {
        d[i - 1] = nums[i] - nums[i - 1];
    }
    vector<vector<long long>> dp(n + 1, vector<long long>(n/2 + 1, INF));
    dp[n][0] = 0;
    dp[n - 1][0] = 0;
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= n / 2; j++) {
            dp[i][j] = dp[i+1][j];
            if (j > 0 && dp[i+2][j-1] != INF)
                dp[i][j] = min(dp[i][j], dp[i+2][j-1] + d[i]);
        }
    }
    int res = 0;
    for (int j = 0; j <= n / 2; j++)
        if (dp[0][j] <= k) res = j;
    cout << res;
    return 0;
}
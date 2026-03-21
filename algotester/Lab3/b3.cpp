#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define INF 10000000000000000LL

int main() {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    sort(nums.begin(), nums.end());

    vector<long long> balance(n - 1);
    for (int i = 0; i < n - 1; i++) balance[i] = nums[i + 1] - nums[i];

    vector<vector<long long>> dp(n + 1, vector<long long>(n / 2 + 1, INF));
    dp[n][0] = 0;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= n / 2; j++) {
            dp[i][j] = dp[i + 1][j];
            if (j > 0 && i + 1 < n && dp[i + 2][j - 1] != INF)
                dp[i][j] = min(dp[i][j], dp[i + 2][j - 1] + balance[i]);
        }
    }

    int res = 0;
    for (int j = 0; j <= n / 2; j++)
        if (dp[0][j] <= k) res = j;
    cout << res << endl;

    return 0;
}
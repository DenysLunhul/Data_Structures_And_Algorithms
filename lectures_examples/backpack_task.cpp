#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct item {
    int price;
    int weight;
};


int main() {
    int n, m;
    cin >> n >> m;
    vector<item> items (n, {0, 0});
    int total_weight = 0;
    for (int i = 0; i < n; i++) {
        cin >> items[i].price >> items[i].weight;
        total_weight += items[i].weight;
    }
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i < n + 1; i++) {
        for (int j = 0; j <= m; j++) {
            if (j - items[i - 1].weight >= 0) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - items[i - 1].weight] + items[i - 1].price);
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[n][m];
    return 0;
}
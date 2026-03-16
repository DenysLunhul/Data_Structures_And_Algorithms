#include <algorithm>
#include  <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int total_sum = 0;
    vector<pair<int, int>> cards(n, {0, 0});
    vector<int> diff(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> cards[i].first >> cards[i].second;
        total_sum += cards[i].first;

        int flip_res = cards[i].second - cards[i].first;
        int remove_res = cards[i].first * -1;
        diff[i] = max(flip_res, remove_res);
    }
    sort(diff.begin(), diff.end());

    for (int i = n - 1; i >= 0; i--) {
        if (diff[i] > 0 and k > 0) {
            total_sum += diff[i];
            k--;
        }
    }
    cout << total_sum;
    return 0;
}
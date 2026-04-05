#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, t;
    cin >> n >> t;
    vector<pair<long long, long long>> workers(n, {0, 0});
    long long res = 0;


    long long max_total = 0;
    long long max_index = 0;
    for (long long i = 0; i < n; i++) {
        cin >> workers[i].first >> workers[i].second;
        if (workers[i].first + workers[i].second > max_total ||
           (workers[i].first + workers[i].second == max_total &&
            workers[i].first < workers[max_index].first)) {
            max_total = workers[i].first + workers[i].second;
            max_index = i;
            }
    }
    t -= max_total;
    res++;
    if (t <= 0) {
        cout << res;
        return 0;
    }

    swap(workers[max_index], workers[n-1]);
    workers.pop_back();
    sort(workers.begin(), workers.end());
    long long sum = 0;
    for (pair<long long , long long> w : workers) {
        sum += w.first;
    }
    if (sum < t) {
        cout << -1;
        return 0;
    }
    long long i = workers.size() - 1;
    while (t > 0) {
        t -= workers[i].first;
        i--;
        res++;

    }
    cout << res;
    return 0;
}
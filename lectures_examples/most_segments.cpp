#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool cmp(pair<int, int> seg1, pair<int, int> seg2) {
    return seg1.second < seg2.second;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> segments(n, {0, 0});
    for (int i = 0; i < n ; i++) {
        pair<int, int> segment;
        cin >> segment.first >> segment.second;
        segments[i] = segment;
    }
    sort(segments.begin(), segments.end(), cmp);
    int res = 0;
    if (segments.empty()){ cout << res; return 0;}
    res = 1;
    int compare_to = 0;
    for (int i = 1; i < n; i++) {
        if (segments[i].first >= segments[compare_to].second) {
            res++;
            compare_to = i;
        }
    }
    cout << res;
    return 0;
}
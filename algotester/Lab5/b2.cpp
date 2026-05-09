#include <bits/stdc++.h>
using namespace std;

long long cross(pair<long long,long long> O, pair<long long,long long> A, pair<long long,long long> B) {
    __int128 v = (__int128)(A.first-O.first)*(B.second-O.second)
               - (__int128)(A.second-O.second)*(B.first-O.first);
    return (v > 0) - (v < 0);
}

vector<pair<long long,long long>> getHull(vector<pair<long long,long long>> pts) {
    int n = pts.size(), k = 0;
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    n = pts.size();
    if (n < 2) return pts;

    vector<pair<long long,long long>> h(2*n);
    for (int i = 0; i < n; i++) {
        while (k >= 2 && cross(h[k-2], h[k-1], pts[i]) <= 0) k--;
        h[k++] = pts[i];
    }
    for (int i = n-2, t = k+1; i >= 0; i--) {
        while (k >= t && cross(h[k-2], h[k-1], pts[i]) <= 0) k--;
        h[k++] = pts[i];
    }
    h.resize(k-1);
    return h;
}

long long latticeOnEdge(pair<long long,long long> a, pair<long long,long long> b) {
    return __gcd(abs(a.first-b.first), abs(a.second-b.second));
}

int main() {
    int n;
    cin >> n;
    vector<pair<long long,long long>> pts(n);
    for (auto& [x,y] : pts) cin >> x >> y;

    auto hull = getHull(pts);
    int m = hull.size();

    long long ans = 0;
    for (int i = 0; i < m; i++)
        ans += latticeOnEdge(hull[i], hull[(i+1)%m]);

    cout << ans;
    return 0;
}
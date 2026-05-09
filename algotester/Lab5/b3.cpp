#include <bits/stdc++.h>
using namespace std;

double EPS = 1e-9;

struct Vec2 {
    double x, y;
    bool operator<(const Vec2& o) const {
        if (fabs(x - o.x) > EPS) return x < o.x;
        if (fabs(y - o.y) > EPS) return y < o.y;
        return false;
    }
};

int main() {
    int n;
    cin >> n;
    set<tuple<int,int,int>> seen;
    vector<tuple<int,int,int>> lines;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        int g = gcd(gcd(abs(a), abs(b)), abs(c));
        if (g > 0) { a /= g; b /= g; c /= g; }
        if (a < 0 || (a == 0 && b < 0)) { a=-a; b=-b; c=-c; }
        if (seen.insert({a, b, c}).second)
            lines.emplace_back(a, b, c);
    }

    long long result = 1;
    for (int i = 0; i < (int)lines.size(); i++) {
        auto [a1, b1, c1] = lines[i];
        set<Vec2> pts;
        for (int j = 0; j < i; j++) {
            auto [a2, b2, c2] = lines[j];
            long long det = (long long)a1*b2 - (long long)a2*b1;
            if (det == 0) continue;
            double x = ((double)c2*b1 - (double)c1*b2) / det;
            double y = ((double)a2*c1 - (double)a1*c2) / det;
            pts.insert({x, y});
        }
        result += (long long)pts.size() + 1;
    }
    cout << result;
    return 0;
}
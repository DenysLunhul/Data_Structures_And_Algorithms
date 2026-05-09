#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int findIndex(vector<int>& a, int val) {
    for (int i = 0; i < a.size(); i++)
        if (a[i] == val)
            return i;
    return -1;
}


int main() {
    int n;
    cin >> n;

    vector<int> x1(n), y1(n), x2(n), y2(n), xs, ys;

    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        xs.push_back(x1[i]); xs.push_back(x2[i]);
        ys.push_back(y1[i]); ys.push_back(y2[i]);
    }

    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());

    vector<int> uxs, uys;
    for (int i = 0; i < xs.size(); i++)
        if (i == 0 || xs[i] != xs[i-1])
            uxs.push_back(xs[i]);

    for (int i = 0; i < ys.size(); i++)
        if (i == 0 || ys[i] != ys[i-1])
            uys.push_back(ys[i]);

    int W = xs.size() - 1, H = ys.size() - 1;
    vector<char> grid(W * H, 0);

    for (int r = 0; r < n; r++) {
        int lx = findIndex(xs, x1[r]);
        int rx = findIndex(xs, x2[r]);
        int ly = findIndex(ys, y1[r]);
        int ry = findIndex(ys, y2[r]);
        for (int i = lx; i < rx; i++)
            for (int j = ly; j < ry; j++)
                grid[i * H + j] = 1;
    }

    long long area = 0;
    for (int i = 0; i < W; i++)
        for (int j = 0; j < H; j++)
            if (grid[i * H + j])
                area += (xs[i+1] - xs[i]) * (ys[j+1] - ys[j]);

    cout << area;
    return 0;
}
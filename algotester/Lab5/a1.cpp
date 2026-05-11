#include <bits/stdc++.h>
using namespace std;


int findIdx(const vector<int>& v, int val) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == val) {
            return i;
        }
    }
    return -1;
}


int main() {
    int n;
    cin >> n;
    vector<int> x1(n), x2(n), y1(n), y2(n), xs, ys;

    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        xs.push_back(x1[i]);
        xs.push_back(x2[i]);
        ys.push_back(y1[i]);
        ys.push_back(y2[i]);
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


    int R = uxs.size() - 1;
    int C = uys.size() - 1;
    vector<vector<char>> grid(R, vector<char>(C, '0'));

    for (int i = 0; i < n; i++) {
        int lx = findIdx(uxs, x1[i]);
        int rx = findIdx(uxs, x2[i]);
        int ly = findIdx(uys, y1[i]);
        int ry = findIdx(uys, y2[i]);
        for (int r = lx; r < rx; r++) {
            for (int c = ly; c < ry; c++) {
                grid[r][c] = '1';
            }
        }
    }
    long long area = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j] == '1') {
                area += (uxs[i+1] - uxs[i]) * (uys[j+1] - uys[j]);
            }
        }
    }
    cout << area;
    return 0;
}
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool adj(int i, int j, double r, double R, int n, int* X, int* Y) {
    if (i > j) swap(i, j);
    if (j < n) {
        double dx = (double)X[i] - X[j];
        double dy = (double)Y[i] - Y[j];
        return (dx * dx + dy * dy) < pow(2 * (r + R), 2);
    }
    if (i == n && j == n + 1) {
        return (X[n+1] - X[n]) < 2 * R;
    }
    if (j == n) {
        return (X[i] - X[n]) < (r + 2 * R);
    }
    if (j == n + 1) {
        return (X[n+1] - X[i]) < (r + 2 * R);
    }
    return false;
}

void dfs(int V, vector<bool>& passed, double r, double R, int n, int* X, int* Y) {
    passed[V] = true;
    for (int i = 0; i < n + 2; i++) {
        if (!passed[i] and adj(V, i, r, R, n, X, Y)) {
            dfs(i, passed, r, R, n, X, Y);
        }
    }
}

bool can(int n, int* X, int* Y, double r, double R) {
    vector<bool> passed(n+2, false);
    dfs(n, passed, r, R, n, X, Y);
    return !passed[n+1];
}

int main() {
    int left, right, r, n;
    cin >> left >> right >> r >> n;
    int X[n + 2];
    int Y[n];
    for (int i = 0; i < n; i++) {
        cin >> X[i] >> Y[i];
    }
    X[n] = left;
    X[n + 1] = right;

    double L = 0;
    double R = right - left;
    for (int i = 0; i < 100; i++) {
        double mid = (L + R) / 2;
        if (can(n, X, Y, r, mid)) {
            L = mid;
        }
        else {
            R = mid;
        }
    }
    cout << L*2;
    return 0;
}
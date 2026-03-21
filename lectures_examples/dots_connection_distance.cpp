#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

double dist(const double* X, const double* Y, const int v, const int i) {
    return sqrt(pow(X[v] - X[i], 2) + pow(Y[v] - Y[i], 2));
}

double f(int v, int mask, const double* X, const double* Y, vector<vector<double>>& mem, int n) {
    if ((1 << v) == mask) {
        return sqrt(X[v] * X[v] + Y[v] * Y[v]);
    }
    if (mem[v][mask] != -1) {
        return mem[v][mask];
    }
    double res = INFINITY;
    for(int i = 0; i < n; i++) {
        if (i != v and ((1 << v) & mask) != -1) {
            double r = dist(X, Y, v, i) + f(i, mask - (1 << v), X, Y, mem, n);
            res = min(res, r);
        }
    }
    mem[v][mask] = res;
    return res;
}


int main() {
    int n;
    cin >> n;
    double X[n];
    double Y[n];
    for (int i = 0; i < n; i++) {
        cin >> X[i] >> Y[i];
    }
    vector<vector<double>> mem(n + 1, vector<double>(1<<n, -1));
    cout << f(0, pow(2, n) - 1, X, Y, mem, n);
    return 0;
}
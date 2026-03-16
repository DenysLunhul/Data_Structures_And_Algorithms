#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool adj(int i, int j, int N, int L, double r, double R, int* X, int* Y) {
    if (i > j) {
        swap(i, j);
        if (j < N) {
            return pow((2 * r + 2 * R), 2) > pow(X[i] - X[j], 2) + pow(Y[i] - Y[j], 2);
        }
        if (i == N) {
            return 2 * R > L;
        }
        if (j == N) {
            return 2 * R + r > X[i];
        }
        return 2 * R + r > L - X[i];
    }
}

void dfs(int N, int L, double r, double R, int* X, int* Y, vector<bool>& visited, int V) {
    visited[V] = true;
    for (int i = 0; i < N + 2; i++) {
        if (!visited[N] and adj(V, V, N, L, r, R, X, Y)) {
            dfs(N, L, r, R, X, Y, visited, i);
        }
    }
}

bool can(int N, int L, double r, double R, int* X, int* Y) {
    vector<bool> visited(N + 2, false);
    dfs(N + 1, L, r, R)
}

int main() {

    return 0;
}
#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int n;
    cin >> n;
    int M = sqrt(n);
    int A[n];
    int B[(n / M) + 1];
    for (int i = 0; i < (n / M) + 1; i++) B[i] = 0;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        B[i / M] += A[i];
    }
    int l, r;
    cin >> l >> r;
    int L = l / M;
    if (l % M != 0) L++;
    int R = r / M;
    int res = 0;
    if (L > R) {
        for (int i = l; i <= r; i++) {
            res += A[i];
        }
        cout << res << endl;
        return 0;
    }
    for (int i = l; i < L * M; i++) {
        res += A[i];
    }
    for (int i = (R * M); i <= r; i++) {
        res += A[i];
    }
    for (int i = L; i < R; i++) {
        res += B[i];
    }
    cout << res << endl;
    return 0;
}
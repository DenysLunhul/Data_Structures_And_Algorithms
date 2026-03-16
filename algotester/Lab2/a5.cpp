#include <iostream>
#include <vector>
using namespace std;

bool check(const vector<int> &papers, long long k, double S) {
    for (int paper : papers) {
        k -= (int)((double)paper / S);
    }
    return k <= 0;
}

int main() {
    double eps = 1e-6;
    long long n, k;
    cin >> n >> k;
    vector<int> papers(n, 0);
    for (long long i = 0 ; i < n; i++) {
        cin >> papers[i];
    }
    double left = 0;
    double right = 1e9;
    while (right - left > eps) {
        double mid = (right + left) / 2;
        if (check(papers, k, mid)) {
            left = mid;
        }
        else {
            right = mid;
        }
    }
    cout << left;
    return 0;
}
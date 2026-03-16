#include <iostream>
#include <vector>
using namespace std;

int sqrt(int n) {
    //Time Complexity - log n
    int left = 0;
    int right = n;
    int mid = (left + right) / 2;
    while (mid*mid != n) {
        if (mid*mid > n) {
            right = mid;
        }
        else {
            left = mid;
        }
        mid = (left + right) / 2;
    }
    return mid;
}

void sieve(int n) {
    //Time Complexity - n log(log n)
    vector<bool> res(n + 1, true);
    res[0] = false;
    res[1] = false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (res[i]) {
            cout << i << " ";
            for (int j = i * i; j <= n; j += i) {
                res[j] = false;
            }
        }
    }
}

int main() {
    sieve(10000);
    return 0;
}
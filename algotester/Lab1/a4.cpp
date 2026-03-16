#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    if (k * 3 < n or n < k) {
        cout << "Impossible";
        return 0;
    }
    while (true) {
        if (n % k == 0) {
            for (int i = 0; i < k; i++) {
                cout << n / k << " ";
            }
            return 0;
        }
        int temp = n / k;
        cout << temp << " ";
        n -= temp;
        k--;
    }
}

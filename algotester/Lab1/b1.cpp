#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    int total = 0;
    for (int i = 1; i <= n; i++) {
        total += pow(i, 2);
    }
    cout << total;
    return 0;
}

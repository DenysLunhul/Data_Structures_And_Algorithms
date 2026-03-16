#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long sum = 0;
    long long num;
    for (long long i = 0; i < n; i++) {
        cin >> num;
        sum += num - 1;
    }
    cout << sum;
    return 0;
}
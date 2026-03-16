#include <iostream>
using namespace std;

void count_nums(unsigned long long n, unsigned long long curr, unsigned long long& total) {
    if (curr > n) {
        return;
    }
    total++;
    if (curr % 10 == 0) {
        count_nums(n, curr * 10 + (curr % 10 + 1), total);
    }
    else if (curr % 10 == 9) {
        count_nums(n, curr * 10 + (curr % 10 - 1), total);
    }
    else{
        count_nums(n, curr * 10 + (curr % 10 + 1), total);
        count_nums(n, curr * 10 + (curr % 10 - 1), total);
    }
}

int main() {
    unsigned long long n;
    unsigned long long total = 0;
    cin >> n;
    for (int i = 1; i <= 9; i++) {
        count_nums(n, i, total);
    }
    cout << total;
    return 0;
}
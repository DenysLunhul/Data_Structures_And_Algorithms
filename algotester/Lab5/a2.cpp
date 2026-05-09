#include <iostream>
#include <cmath>

using namespace std;


long long gcd(long long a, long long b) {
    a = abs(a);
    b = abs(b);
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void frac(long long num, long long den) {
    if (den < 0) {
        num *= -1;
        den *= -1;
    }
    long long temp = gcd(num, den);
    num /= temp;
    den /= temp;
    cout << num << "/" << den;
}

int main() {
    long long x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    long long A1 = y2 - y1;
    long long B1 = x1 - x2;
    long long C1 = A1 * x1 + B1 * y1;

    long long A2 = y4 - y3;
    long long B2 = x3 - x4;
    long long C2 = A2 * x3 + B2 * y3;
    
    long long D = A1 * B2 - A2 * B1;
    long long Dx = C1 * B2 - C2 * B1;
    long long Dy = A1 * C2 - A2 * C1;


    frac(Dx, D);
    cout << " ";
    frac(Dy, D);
    return 0;
}
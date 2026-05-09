#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    double d = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
    if (d <= abs(r1 - r2)) {
        double r = min(r1, r2);
        cout << M_PI * r * r;
        return 0;
    }
    if (d >= r1 + r2) {
        cout << 0;
        return 0;
    }
    double a1 = 2 * acos((d*d + r1*r1 - r2*r2) / (2*d*r1));
    double a2 = 2 * acos((d*d + r2*r2 - r1*r1) / (2*d*r2));
    double area = 0.5*r1*r1*(a1 - sin(a1)) + 0.5*r2*r2*(a2 - sin(a2));
    cout << area;
    return 0;
}
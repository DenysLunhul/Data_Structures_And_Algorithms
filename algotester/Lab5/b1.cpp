#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;

double pointToRay(double px, double py, double ax, double ay, double vx, double vy) {
    double len_sq = vx*vx + vy*vy;
    double t = ((px-ax)*vx + (py-ay)*vy) / len_sq;

    if (t <= 0.0) {
        return hypot(px-ax, py-ay);
    } else {
        double nx = ax + t*vx;
        double ny = ay + t*vy;
        return hypot(px-nx, py-ny);
    }
}

int main() {
    double x1, y1, dx1, dy1;
    double x2, y2, dx2, dy2;
    cin >> x1 >> y1 >> dx1 >> dy1;
    cin >> x2 >> y2 >> dx2 >> dy2;
    double D    =  dx1*dy2 - dy1*dx2;
    double Dt1  =  (x2-x1)*dy2 - (y2-y1)*dx2;
    double Dt2  =  (x2-x1)*dy1 - (y2-y1)*dx1;
    if (D != 0.0) {
        double t1 = Dt1 / D;
        double t2 = Dt2 / D;
        if (t1 >= 0.0 && t2 >= 0.0) {
            cout << fixed << setprecision(8) << 0.0;
            return 0;
        }
    }
    double d1 = pointToRay(x1, y1, x2, y2, dx2, dy2);
    double d2 = pointToRay(x2, y2, x1, y1, dx1, dy1);
    cout << fixed << setprecision(8) << min(d1, d2);
    return 0;
}
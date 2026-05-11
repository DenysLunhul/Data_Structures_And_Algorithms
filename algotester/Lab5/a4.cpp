#include <iostream>
#include <cmath>
using namespace std;


int main() {
    double px, py, ax, ay, bx, by;
    cin >> px >> py >> ax >> ay >> bx >> by;
    double dx = bx - ax;
    double dy = by - ay;
    double l2 = dx * dx + dy * dy;
    if (l2 == 0.0) {
        double pdx = px - ax;
        double pdy = py - ay;
        cout << pdx * pdx + pdy * pdy;
        return 0;
    }
    double t = ((px - ax) * dx + (py - ay) * dy) / l2;
    if (t < 0.0) {
        t = 0.0;
    } else if (t > 1.0) {
        t = 1.0;
    }
    double closest_x = ax + t * dx;
    double closest_y = ay + t * dy;
    double res_dx = px - closest_x;
    double res_dy = py - closest_y;
    cout << pow(res_dx * res_dx + res_dy * res_dy, 0.5);
    return 0;
}

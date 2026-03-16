#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double get_distance(double t,
                    double x1, double y1, double z1,
                    double x2, double y2, double z2,
                    double vx1, double vy1, double vz1,
                    double vx2, double vy2, double vz2) {

    double dx = (x1 + vx1 * t) - (x2 + vx2 * t);
    double dy = (y1 + vy1 * t) - (y2 + vy2 * t);
    double dz = (z1 + vz1 * t) - (z2 + vz2 * t);

    return sqrt(dx * dx + dy * dy + dz * dz);
}

double closest_time(double x1, double y1, double z1,
                    double x2, double y2, double z2,
                    double vx1, double vy1, double vz1,
                    double vx2, double vy2, double vz2) {

    double low = 0;
    double high = 1e9;
    for (int i = 0; i < 100; i++) {
        double m1 = low + (high - low) / 3.0;
        double m2 = high - (high - low) / 3.0;
        double dist1 = get_distance(m1, x1, y1, z1, x2, y2, z2, vx1, vy1, vz1, vx2, vy2, vz2);
        double dist2 = get_distance(m2, x1, y1, z1, x2, y2, z2, vx1, vy1, vz1, vx2, vy2, vz2);

        if (dist1 < dist2) {
            high = m2;
        } else {
            low = m1;
        }
    }

    return low;
}

int main() {
    double x1, y1, z1, x2, y2, z2;
    double vx1, vy1, vz1, vx2, vy2, vz2;

    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> vx1 >> vy1 >> vz1 >> vx2 >> vy2 >> vz2;

    double t = closest_time(x1, y1, z1, x2, y2, z2, vx1, vy1, vz1, vx2, vy2, vz2);
    double minDist = get_distance(t, x1, y1, z1, x2, y2, z2, vx1, vy1, vz1, vx2, vy2, vz2);
    cout << t << " " << minDist;
    return 0;
}
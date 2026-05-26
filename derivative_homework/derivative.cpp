#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

double derive(double (*func)(double), double x, double h = 1e-6) {
    return (func(x + h) - func(x - h)) / (2.0 * h);
}

double my_sin(double x) { return sin(x); }

double my_exp(double x) { return exp(x); }

double my_pow3(double x) { return pow(x, 3); }

double my_sqrt(double x) { return sqrt(x); }

int main() {
    double dx = 0.005;
    double h = 1e-7;

    cout << fixed << setprecision(5);

    struct FunctionInfo {
        string name;
        string fileName;
        string plotName;
        double (*ptr)(double);
        double xstart;
        double xend;
    };

    const double PI = acos(-1.0);

    FunctionInfo functions[] = {
        {"sin(x)",  "sin_data.dat",  "sin_plot.png",  my_sin,  -2*PI, 2*PI},
        {"exp(x)",  "exp_data.dat",  "exp_plot.png",  my_exp,  -3.0,  3.0 },
        {"x^3",     "pow3_data.dat", "pow3_plot.png", my_pow3, -5.0,  5.0 },
        {"sqrt(x)", "sqrt_data.dat", "sqrt_plot.png", my_sqrt,  0.01, 10.0}
    };

    ofstream script("plot_all.gp");

    script << "set terminal pngcairo size 1200,800 enhanced font 'Arial,13'\n";
    script << "set grid lw 1 lc rgb '#cccccc'\n";
    script << "set border lw 1.5\n";
    script << "set xlabel 'x' font 'Arial,13'\n";
    script << "set ylabel 'y' font 'Arial,13'\n";
    script << "set key top left font 'Arial,12'\n";
    script << "set style line 1 lc rgb '#0060ad' lw 2.5\n";
    script << "set style line 2 lc rgb '#dd181f' lw 2.5 dt 2\n";

    for (const auto& f_info : functions) {
        ofstream dataFile(f_info.fileName);

        if (!dataFile) {
            cerr << "Cannot open file: " << f_info.fileName << endl;
            return 1;
        }

        cout << "--- Analysis of function: " << f_info.name << " ---" << endl;
        cout << "x\t\t | f(x)\t\t | f'(x) approx" << endl;
        cout << "----------------------------------------------------" << endl;
        dataFile << "# x f(x) derivative\n";

        for (double x = f_info.xstart; x <= f_info.xend; x += dx) {
            double val = f_info.ptr(x);
            double d_val = derive(f_info.ptr, x, h);
            cout << x << "\t | " << val << "\t | " << d_val << endl;
            dataFile << x << " " << val << " " << d_val << '\n';
        }
        cout << endl;
        script << "set output '" << f_info.plotName << "'\n";
        script << "set title '" << f_info.name << " and its derivative' font 'Arial,15'\n";
        script << "set xrange [" << f_info.xstart << ":" << f_info.xend << "]\n";
        script << "set autoscale y\n";
        script << "plot '" << f_info.fileName << "' using 1:2 with lines ls 1 title '" << f_info.name << "', ";
        script << "'" << f_info.fileName << "' using 1:3 with lines ls 2 title \"f'(x) (derivative)\"\n";
    }
    script.close();
    cout << "Data files and gnuplot script were generated." << endl;
    cout << "Run this command to create plots:" << endl;
    cout << "gnuplot plot_all.gp" << endl;
    return 0;
}
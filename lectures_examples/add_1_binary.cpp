#include <iostream>
#include <vector>
using namespace std;


int power_2(int n) {
    return 1 << n;
}


void add_1_binary(vector<int>& number) {
    for (int i = 0; i < number.size(); i++) {
        if (number[i] == 0) {
            number[i] = 1;
            break;
        }
        else {
            number[i] = 0;
        }
    }
}


int main() {
    vector<int> number = {0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < power_2(8); i++) {
        for (int i = number.size() - 1; i >= 0; i--) {
            cout << number[i];
        }
        add_1_binary(number);
        cout << endl;
    }
    return 0;
}
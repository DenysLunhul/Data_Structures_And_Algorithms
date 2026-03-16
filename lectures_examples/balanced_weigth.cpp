#include <iostream>
#include <vector>
using namespace std;

void balanced_weights(vector<int>& weights, vector<int>& sides) {
    //Time Complexity - n * 2^n
    if (sides.size() == weights.size()) {
        int res = 0;
        for (int i = 0; i < sides.size(); i++) {
            res += sides[i] * weights[i];
        }
        if (res == 0) {
            for (int side: sides) {
                if (side == -1) {
                    cout << "L";
                }
                else {
                    cout << "R";
                }
            }
            cout << endl;
        }
        return;
    }

    sides.push_back(-1);
    balanced_weights(weights, sides);
    sides.back() = 1;
    balanced_weights(weights, sides);
    sides.pop_back();
}

int main() {
    vector<int> weights = {3, 4, 3, 8, 4};
    vector<int> sides = {};
    balanced_weights(weights, sides);
    return 0;
}
#include <vector>
#include <algorithm>
using namespace std;

void quick_sort(vector<int>& v, int* l, int* r) {
    if (l + 1 >= r) {
        return;
    }

    int pivot = v[*l];
    int* ll = l + 1;
    int* rr = r;

    while (ll < rr) {
        if (v[*ll] < pivot) {
            ll++;
        } else {
            rr--;
            swap(v[*ll], v[*rr]);
        }
    }

    swap(v[*l], v[*(rr - 1)]);

    quick_sort(v, l, rr - 1); // [l, rr-1)
    quick_sort(v, rr, r);     // [rr, r)
}

int main() {
    return 0;
}
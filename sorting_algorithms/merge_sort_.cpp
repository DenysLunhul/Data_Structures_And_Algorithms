#include <iostream>
using namespace std;



void merge_sort(int* l, int* r, int* temp) {
    if (r - l <= 1) {
        return;
    }
    int* m = l + (r - l) / 2;
    merge_sort(l, m, temp);
    merge_sort(m, r, temp);
    int i = 0;
    int* ll = l;
    int* mm = m;
    while (ll < m and mm < r) {
        if (*ll < *mm) {
            temp[i++] = *ll++;
        }
        else {
            temp[i++] = *mm++;
        }
    }
    while (ll < m) {
        temp[i++] = *ll++;
    }
    while (mm < r) {
        temp[i++] = *mm++;
    }
    i = 0;
    while (l < r) {
        *l++ = temp[i++];
    }
}

int main() {
    int n;
    cin >> n;
    int temp[n];
    return 0;
}
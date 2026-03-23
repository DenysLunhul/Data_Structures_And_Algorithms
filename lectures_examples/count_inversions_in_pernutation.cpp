#include <iostream>
using namespace std;

//Array like [1, 3, 4, 6, 2, 5]
//Inversions are (3, 2) (4, 2) (6, 2) (6, 5)

void merge_sort(int* l, int* r, int* temp, int& inv) {
    if (r - l <= 1) {
        return;
    }
    int* m = l + (r - l) / 2;
    merge_sort(l, m, temp, inv);
    merge_sort(m, r, temp, inv);
    int i = 0;
    int* ll = l;
    int* mm = m;
    while (ll < m and mm < r) {
        if (*ll < *mm) {
            temp[i++] = *ll++;
        }
        else {
            inv += m - ll; //key cahnge in merge sort to count inversions
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
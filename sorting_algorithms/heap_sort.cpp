#include <algorithm>
#include <vector>
#include "../data_structures/heap.h"
using namespace std;


//default
void heap_sort(vector<int>& v) {
    Heap heap;
    for (auto a: v) {
        heap.push(a);
    }
    v.clear();
    while (heap.size() > 0) {
        v.push_back(heap.top());
        heap.pop();
    }
    reverse(v.begin(), v.end());
}


void heap_sort_(vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        int index = i;
        while (index > 0 and v[(index + 1) / 2 - 1] < v[index]) {
            swap(v[(index + 1) / 2 - 1], v[index]);
            index = (index + 1) / 2 - 1;
        }
    }
    for (int i = 0; i < v.size(); i++) {
        swap(v[0], v[v.size() - 1 - i]);
        int index = 0;
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < v.size() - i - 1 && v[left] > v[largest]) largest = left;
            if (right < v.size() - i - 1 && v[right] > v[largest]) largest = right;

            if (largest == index) break;
            swap(v[index], v[largest]);
            index = largest;
        }
    }
}



int main() {
    return 0;
}
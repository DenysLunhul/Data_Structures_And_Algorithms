#ifndef HEAP_H
#define HEAP_H

#include <vector>
using namespace std;

struct Heap {
    vector<int> tree = {0};

    void push(int a);
    void pop();
    int top();
    int size();
};

#endif
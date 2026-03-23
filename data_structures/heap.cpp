#include "heap.h"

void Heap::push(int a) {
    tree.push_back(a);
    int index = (int)tree.size() - 1;
    while(index > 1 and tree[index] > tree[index / 2]) {
        swap(tree[index], tree[index / 2]);
        index /= 2;
    }
}

void Heap::pop() {
    swap(tree[1], tree.back());
    tree.pop_back();
    int index = 1;
    while (index * 2 < (int)tree.size()) {
        int c = index * 2;
        if (c + 1 < (int)tree.size() and tree[c + 1] > tree[c]) {
            c++;
        }
        if (tree[c] > tree[index]) {
            swap(tree[c], tree[index]);
            index = c;
        }
        else break;
    }
}

int Heap::top() {
    return tree[1];
}

int Heap::size() {
    return tree.size() - 1;
}
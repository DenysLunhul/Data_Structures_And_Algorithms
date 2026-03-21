#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val): data(val), next(nullptr){}
};

class SinglyLinkedList {
private:
    Node* head;
    int size;

public:
    SinglyLinkedList(): head(nullptr), size(0){}
    ~SinglyLinkedList();

    void pushFront(int val);
    void pushBack(int val);
    void insertAt(int index, int val);

    void popFront();
    void popBack();
    void removeAt(int index);

    int get(int index) const {
        Node* current = head;
        for (int i = 0; i < index; i++) {
            if (current == nullptr) {
                return -1;
            }
            current = current->next;
        }
        return current->data;
    }

    int find(int val) {
        int index = 0;
        Node* current = head;
        while (current != nullptr and current->data != val) {
            index++;
            current = current->next;
        }
        return index;
    }

    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        if (current == nullptr) {
            return;
        }
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    void print() const {
        Node* current = head;
        if (current == nullptr) {
            return;
        }
        while (current != nullptr) {
            cout << current->data;
            current = current->next;
        }
    }

    int getSize() const {
        return size;
    }

    bool isEmpty() const {
        return getSize() == 0;
    }
};
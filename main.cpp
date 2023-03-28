#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Queue {
private:
    Node* head;
    Node* tail;
    int count;

public:
    Queue() {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    void enqueue(int x) {
        Node* newNode = new Node;
        newNode->data = x;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        count++;
    }

    void dequeue() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        if (head == nullptr) {
            tail = nullptr;
        }
        count--;
    }

    int top() {
        if (head != nullptr) {
            return head->data;
        }
    }


    int size() {
        return count;
    }
};

int main() {
    Queue example;
    example.enqueue(25);
    example.enqueue(50);
    example.enqueue(100);
    example.enqueue(200);
    example.enqueue(500);
    cout << "Size of queue is " << example.size() << endl;
    cout << "Top element is " << example.top() << endl;
    example.dequeue();
    cout << "Top element is " << example.top() << endl;
    example.dequeue();
    cout << "Top element is " << example.top() << endl;
    cout << "Size of queue is " << example.size() << endl;
    return 0;
}


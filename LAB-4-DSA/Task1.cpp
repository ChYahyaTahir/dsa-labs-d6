#include <iostream>
using namespace std;

template <typename T>
class AbstractQueue {
public:
    virtual void enQ(T val) = 0;
    virtual T deQ() = 0;
    virtual T getFront() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual ~AbstractQueue() {}
};

template <typename T>
class MyQueue : public AbstractQueue<T> {
private:
    T* arr;
    int front, rear, size, cap;

public:
    MyQueue(int c) {
        cap = c;
        arr = new T[cap];
        front = 0;
        rear = -1;
        size = 0;
    }

    void enQ(T val) {
        if (isFull()) {
            cout << "Full\n";
            return;
        }
        rear = (rear + 1) % cap;
        arr[rear] = val;
        size++;
    }

    T deQ() {
        if (isEmpty()) {
            cout << "Empty\n";
            return -1;
        }
        T val = arr[front];
        front = (front + 1) % cap;
        size--;
        return val;
    }

    T getFront() const { return arr[front]; }
    bool isEmpty() const { return size == 0; }
    bool isFull() const { return size == cap; }

    void display() const {
        if (isEmpty()) {
            cout << "Empty\n";
            return;
        }
        for (int i = 0; i < size; i++) {
            cout << arr[(front + i) % cap] << " ";
        }
        cout << endl;
    }
};

int main() {
    MyQueue<int> q(5);
    int choice, val;

    while (true) {
        cout << "\n1.Enqueue 2.Dequeue 3.Front 4.Display 5.Exit\n";
        cin >> choice;

        if (choice == 1) {
            cin >> val;
            q.enQ(val);
        } else if (choice == 2) {
            cout << "Removed: " << q.deQ() << endl;
        } else if (choice == 3) {
            cout << "Front: " << q.getFront() << endl;
        } else if (choice == 4) {
            q.display();
        } else if (choice == 5) {
            break;
        }
    }
    return 0;
}
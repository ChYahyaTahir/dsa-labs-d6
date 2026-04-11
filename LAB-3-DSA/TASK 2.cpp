#include <iostream>
#include <stack> 
using namespace std;

template <typename T>
class AbstractStack {
public:
    virtual void push(T value) = 0;
    virtual T pop() = 0;
    virtual T top() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual ~AbstractStack() {}
};

template <typename T>
class myStack : public AbstractStack<T> {
private:
    T* arr;
    int topIndex;
    int capacity;
    stack<T> minStack;

public:
    myStack(int size) {
        capacity = size;
        arr = new T[capacity];
        topIndex = -1;
    }

    ~myStack() { delete[] arr; }

    void push(T value) {
        if (isFull()) {
            cout << "Stack Overflow!\n";
            return;
        }
        arr[++topIndex] = value;

        if (minStack.empty() || value <= minStack.top())
            minStack.push(value);
    }

    T pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!\n";
            return -1;
        }

        T popped = arr[topIndex--];
        if (!minStack.empty() && popped == minStack.top())
            minStack.pop();
        return popped;
    }

    T top() const {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return arr[topIndex];
    }

    T getMin() const {
        if (minStack.empty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return minStack.top();
    }

    bool isEmpty() const { return topIndex == -1; }
    bool isFull() const { return topIndex == capacity - 1; }

    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements (Top to Bottom): ";
        for (int i = topIndex; i >= 0; i--) cout << arr[i] << " ";
        cout << endl;
    }
};
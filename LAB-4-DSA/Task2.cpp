#include <iostream>
#include <stack>
using namespace std;

class QueueStack 
{
    stack<int> s1, s2;

public:
    void enQ(int val) 
{
        s1.push(val);
    }

    void move()
 {
        while (!s1.empty()) 
{
            s2.push(s1.top());
            s1.pop();
        }
    }

    int deQ() 
{
        if (s2.empty()) move();
        if (s2.empty()) return -1;

        int res = s2.top();
        s2.pop();
        return res;
    }

    int getFront() {
        if (s2.empty()) move();
        if (s2.empty()) return -1;
        return s2.top();
    }

    void show() {
        stack<int> t1 = s2;
        stack<int> t2 = s1;

        while (!t1.empty()) {
            cout << t1.top() << " ";
            t1.pop();
        }

        stack<int> rev;
        while (!t2.empty()) {
            rev.push(t2.top());
            t2.pop();
        }

        while (!rev.empty()) {
            cout << rev.top() << " ";
            rev.pop();
        }
        cout << endl;
    }
};

int main() {
    QueueUsingStack q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();
    cout << "Dequeue: " << q.dequeue() << endl;
    q.display();
}
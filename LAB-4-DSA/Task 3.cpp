#include <iostream>
#include <stack>
using namespace std;

template <typename T>
class Queue {
    T* arr;
    int f, r, s, cap;
public:
    Queue(int c) {
        cap = c;
        arr = new T[cap];
        f = 0; r = -1; s = 0;
    }
    void enQ(T v) {
        if (s == cap) return;
        r = (r + 1) % cap;
        arr[r] = v;
        s++;
    }
    T deQ() {
        if (isEmpty()) return -1;
        T v = arr[f];
        f = (f + 1) % cap;
        s--;
        return v;
    }
    T getF() { return (isEmpty()) ? -1 : arr[f]; }
    bool isEmpty() { return s == 0; }
    int getSize() { return s; }
    void show() {
        for (int i = 0; i < s; i++) cout << arr[(f + i) % cap] << " ";
        cout << endl;
    }
};

void reverseK(Queue<int>& q, int k) {
    if (q.isEmpty() || k <= 1) return;
    if (k > q.getSize()) k = q.getSize();

    stack<int> st;
    for (int i = 0; i < k; i++) st.push(q.deQ());
    while (!st.empty()) {
        q.enQ(st.top());
        st.pop();
    }
    for (int i = 0; i < q.getSize() - k; i++) q.enQ(q.deQ());
}

int main() {
    int n, k, v;
    cout << "Enter Queue Size: "; cin >> n;
    Queue<int> q(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) { cin >> v; q.enQ(v); }
    cout << "Enter K: "; cin >> k;

    reverseK(q, k);
    cout << "Output: "; q.show();
    return 0;
}
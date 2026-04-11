#include <iostream>
#include <string>
using namespace std;

class PrintQueue {
    string* q;
    int f, r, s, cap;
public:
    PrintQueue(int c) {
        cap = c;
        q = new string[cap];
        f = 0; r = -1; s = 0;
    }
    void enQ(string doc) {
        if (s == cap) { cout << "Queue Full\n"; return; }
        r = (r + 1) % cap;
        q[r] = doc;
        s++;
    }
    void deQ() {
        if (s == 0) { cout << "No documents to print.\n"; return; }
        cout << "Printing: " << q[f] << endl;
        f = (f + 1) % cap;
        s--;
    }
    void peek() {
        if (s == 0) cout << "Queue Empty\n";
        else cout << "Next: " << q[f] << endl;
    }
    void show() {
        if (s == 0) { cout << "Empty\n"; return; }
        cout << "Queue: ";
        for (int i = 0; i < s; i++) cout << q[(f + i) % cap] << " | ";
        cout << endl;
    }
};

int main() {
    PrintQueue pq(10);
    int choice;
    string name;
    while (true) {
        cout << "\n1.Add Doc 2.Print 3.Front 4.Show All 5.Exit\n";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter Name: "; cin >> name;
            pq.enQ(name);
        } else if (choice == 2) pq.deQ();
        else if (choice == 3) pq.peek();
        else if (choice == 4) pq.show();
        else if (choice == 5) break;
    }
    return 0;
}
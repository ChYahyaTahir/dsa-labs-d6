#include <iostream>
using namespace std;

class TicketSystem {
    int *q, f, r, s, cap;
public:
    TicketSystem(int c) {
        cap = c;
        q = new int[cap];
        f = 0; r = -1; s = 0;
    }
    void addTicket(int id) {
        if (s == cap) { cout << "Queue Full\n"; return; }
        r = (r + 1) % cap;
        q[r] = id;
        s++;
        cout << "Ticket " << id << " added.\n";
    }
    void resolve() {
        if (s == 0) { cout << "No tickets.\n"; return; }
        cout << "Resolved: " << q[f] << endl;
        f = (f + 1) % cap;
        s--;
    }
    void peek() {
        if (s == 0) cout << "No pending tickets.\n";
        else cout << "Next: " << q[f] << endl;
    }
    void display() {
        if (s == 0) { cout << "Empty\n"; return; }
        cout << "Pending: ";
        for (int i = 0; i < s; i++) cout << q[(f + i) % cap] << " ";
        cout << endl;
    }
};

int main() {
    TicketSystem ts(10);
    int choice, id;
    while (true) {
        cout << "\n1.Add 2.Resolve 3.Next 4.Show All 5.Exit\n";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter 4-digit ID: "; cin >> id;
            ts.addTicket(id);
        } else if (choice == 2) ts.resolve();
        else if (choice == 3) ts.peek();
        else if (choice == 4) ts.display();
        else if (choice == 5) break;
    }
    return 0;
}
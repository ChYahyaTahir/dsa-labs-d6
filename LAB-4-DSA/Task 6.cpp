#include <iostream>
#include <string>
using namespace std;

struct Package {
    int id;
    string addr;
    int start, end;
};

class DeliverySystem {
    Package* q;
    int f, r, s, cap;
public:
    DeliverySystem(int c) {
        cap = c;
        q = new Package[cap];
        f = 0; r = -1; s = 0;
    }
    void enQ(int id, string addr, int st, int en) {
        if (s == cap) return;
        r = (r + 1) % cap;
        q[r] = {id, addr, st, en};
        s++;
    }
    void deQ() {
        if (s == 0) return;
        cout << "Delivered ID: " << q[f].id << endl;
        f = (f + 1) % cap;
        s--;
    }
    void checkTime(int currTime) {
        if (s == 0) return;
        if (currTime > q[f].end) {
            cout << "Package " << q[f].id << " Expired. Removing...\n";
            f = (f + 1) % cap;
            s--;
        } else {
            cout << "Package " << q[f].id << " is valid for delivery.\n";
        }
    }
    void show() {
        for (int i = 0; i < s; i++) {
            Package p = q[(f + i) % cap];
            cout << "ID: " << p.id << " | Addr: " << p.addr << " | Window: " << p.start << "-" << p.end << endl;
        }
    }
};

int main() {
    DeliverySystem ds(5);
    int choice, id, sT, eT, curr;
    string addr;
    while (true) {
        cout << "\n1.Add 2.Deliver 3.Check Time 4.Show 5.Exit\n";
        cin >> choice;
        if (choice == 1) {
            cout << "ID, Addr, Start, End: ";
            cin >> id >> addr >> sT >> eT;
            ds.enQ(id, addr, sT, eT);
        } else if (choice == 2) ds.deQ();
        else if (choice == 3) {
            cout << "Current Time: "; cin >> curr;
            ds.checkTime(curr);
        } else if (choice == 4) ds.show();
        else if (choice == 5) break;
    }
    return 0;
}
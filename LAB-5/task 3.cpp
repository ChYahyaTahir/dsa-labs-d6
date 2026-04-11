#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    queue<string> emergency, passenger, cargo;
    int choice;
    string flight;

    do {
        cout << "\n1.Add Flight 2.Land Flight 3.Exit\n";
        cin >> choice;

        if (choice == 1) {
            int type;
            cout << "Flight type? 1-Emergency 2-Passenger 3-Cargo: ";
            cin >> type;
            cout << "Flight name: ";
            cin >> flight;
            if (type == 1) emergency.push(flight);
            else if (type == 2) passenger.push(flight);
            else cargo.push(flight);
        }
        else if (choice == 2) {
            if (!emergency.empty()) {
                cout << "Landing Emergency Flight: " << emergency.front() << endl;
                emergency.pop();
            }
            else if (!passenger.empty()) {
                cout << "Landing Passenger Flight: " << passenger.front() << endl;
                passenger.pop();
            }
            else if (!cargo.empty()) {
                cout << "Landing Cargo Flight: " << cargo.front() << endl;
                cargo.pop();
            }
            else {
                cout << "No flights waiting" << endl;
            }
        }
    } while (choice != 3);

    return 0;
}
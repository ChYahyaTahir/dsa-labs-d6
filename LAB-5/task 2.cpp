#include <iostream>
#include <string>
using namespace std;

struct Student {
    int roll;
    string name;
    int marks;
    Student* next;
};

Student* head = NULL;

void insertAtEnd(int r, string n, int m) {
    Student* newNode = new Student;
    newNode->roll = r;
    newNode->name = n;
    newNode->marks = m;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Student* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void display() {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    Student* temp = head;
    cout << "Roll\tName\tMarks\n";
    while (temp != NULL) {
        cout << temp->roll << "\t" << temp->name << "\t" << temp->marks << endl;
        temp = temp->next;
    }
}

void deleteByRoll(int r) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    if (head->roll == r) {
        Student* temp = head;
        head = head->next;
        delete temp;
        cout << "Deleted" << endl;
        return;
    }
    Student* temp = head;
    while (temp->next != NULL && temp->next->roll != r) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        cout << "Roll not found" << endl;
        return;
    }
    Student* del = temp->next;
    temp->next = temp->next->next;
    delete del;
    cout << "Deleted" << endl;
}

void search(int r) {
    Student* temp = head;
    while (temp != NULL) {
        if (temp->roll == r) {
            cout << "Found: " << temp->roll << " " << temp->name << " " << temp->marks << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Student not found" << endl;
}

void update(int r) {
    Student* temp = head;
    while (temp != NULL) {
        if (temp->roll == r) {
            cout << "Enter new name: ";
            cin >> temp->name;
            cout << "Enter new marks: ";
            cin >> temp->marks;
            cout << "Updated" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Student not found" << endl;
}

void statistics() {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    int maxM = head->marks, minM = head->marks, sum = 0, count = 0;
    Student* temp = head;
    while (temp != NULL) {
        if (temp->marks > maxM) maxM = temp->marks;
        if (temp->marks < minM) minM = temp->marks;
        sum += temp->marks;
        count++;
        temp = temp->next;
    }
    cout << "Highest: " << maxM << ", Lowest: " << minM << ", Average: " << (sum * 1.0 / count) << endl;
}

int main() {
    int choice;
    do {
        cout << "\n1.Insert 2.Delete 3.Display 4.Search 5.Update 6.Stats 0.Exit\n";
        cin >> choice;
        if (choice == 1) {
            int r, m; string n;
            cout << "Roll, Name, Marks: ";
            cin >> r >> n >> m;
            insertAtEnd(r, n, m);
        }
        else if (choice == 2) {
            int r;
            cout << "Roll to delete: ";
            cin >> r;
            deleteByRoll(r);
        }
        else if (choice == 3) {
            display();
        }
        else if (choice == 4) {
            int r;
            cout << "Roll to search: ";
            cin >> r;
            search(r);
        }
        else if (choice == 5) {
            int r;
            cout << "Roll to update: ";
            cin >> r;
            update(r);
        }
        else if (choice == 6) {
            statistics();
        }
    } while (choice != 0);

    return 0;
}
#include <iostream>
#include <stack>
using namespace std;

class myCarStack {
private:
    string cars[8]; // max 8 cars
    int topIndex;
    int capacity;

public:
    myCarStack() {
        topIndex = -1;
        capacity = 8;
    }

    bool isEmpty() { return topIndex == -1; }
    bool isFull() { return topIndex == capacity - 1; }

    void parkCar(string carNumber) {
        if (isFull()) {
            cout << "Parking Full!\n";
            return;
        }
        cars[++topIndex] = carNumber;
        cout << carNumber << " parked.\n";
    }

    void removeCar(string carNumber) {
        if (isEmpty()) {
            cout << "Parking Empty!\n";
            return;
        }

        stack<string> temp; // temporary stack
        bool found = false;

        // move cars until target car found
        while (!isEmpty()) {
            if (cars[topIndex] == carNumber) {
                cout << carNumber << " removed from parking.\n";
                topIndex--;
                found = true;
                break;
            }
            else {
                temp.push(cars[topIndex--]);
            }
        }

        // put back temporarily removed cars
        while (!temp.empty()) {
            cars[++topIndex] = temp.top();
            temp.pop();
        }

        if (!found) cout << carNumber << " not found in parking.\n";
    }

    void displayCars() {
        if (isEmpty()) {
            cout << "Parking Empty!\n";
            return;
        }
        cout << "Cars in parking (Top to Bottom): ";
        for (int i = topIndex; i >= 0; i--) cout << cars[i] << " ";
        cout << endl;
    }

    void totalCars() { cout << "Total Cars: " << (topIndex + 1) << endl; }

    void searchCar(string carNumber) {
        bool found = false;
        for (int i = 0; i <= topIndex; i++) {
            if (cars[i] == carNumber) {
                found = true;
                break;
            }
        }
        cout << (found ? "Car is in parking.\n" : "Car not found.\n");
    }
};
3.4)#include <iostream>
#include <stack>
using namespace std;

struct Action {
    string type; // "insert" or "delete"
    string data;
};

class TextEditor {
private:
    string text;
    stack<Action> undoStack;
    stack<Action> redoStack;

public:
    void typeText(string s) {
        text += s;
        undoStack.push({ "insert", s });
        while (!redoStack.empty()) redoStack.pop(); // redo cleared
    }

    void deleteText(int n) {
        if (n > text.size()) n = text.size();
        string deleted = text.substr(text.size() - n, n);
        text.erase(text.size() - n, n);
        undoStack.push({ "delete", deleted });
        while (!redoStack.empty()) redoStack.pop();
    }

    void undo() {
        if (undoStack.empty()) {
            cout << "Nothing to undo.\n";
            return;
        }

        Action last = undoStack.top(); undoStack.pop();

        if (last.type == "insert") {
            text.erase(text.size() - last.data.size(), last.data.size());
            redoStack.push(last);
        }
        else if (last.type == "delete") {
            text += last.data;
            redoStack.push(last);
        }
    }

    void redo() {
        if (redoStack.empty()) {
            cout << "Nothing to redo.\n";
            return;
        }

        Action last = redoStack.top(); redoStack.pop();

        if (last.type == "insert") {
            text += last.data;
            undoStack.push(last);
        }
        else if (last.type == "delete") {
            text.erase(text.size() - last.data.size(), last.data.size());
            undoStack.push(last);
        }
    }

    void showText() {
        cout << "Current Text: \"" << text << "\"\n";
    }
};

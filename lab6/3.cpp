#include <iostream>
using namespace std;

// Node structure
struct Node {
	int data;
	Node* next;
};

Node* head = nullptr;


int countNodes() {
	int count = 0;
	Node* temp = head;

	while (temp != nullptr) {
		count++;
		temp = temp->next;
	}
	return count;
}


void insertAtPosition(int value, int position) {
	int total = countNodes();

	if (position < 1 || position > total + 1) {
		cout << "Invalid position!\n";
		return;
	}

	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = nullptr;

	// Insert at beginning
	if (position == 1) {
		newNode->next = head;
		head = newNode;
		return;
	}

	Node* temp = head;
	for (int i = 1; i < position - 1; i++) {
		temp = temp->next;
	}

	newNode->next = temp->next;
	temp->next = newNode;
}


void deleteAtPosition(int position) {
	int total = countNodes();

	if (position < 1 || position > total) {
		cout << "Invalid position!\n";
		return;
	}

	Node* temp = head;

	if (position == 1) {
		head = head->next;
		delete temp;
		cout << "Node deleted.\n";
		return;
	}

	Node* prev = nullptr;
	for (int i = 1; i < position; i++) {
		prev = temp;
		temp = temp->next;
	}

	prev->next = temp->next;
	delete temp;
	cout << "Node deleted.\n";
}

void searchElement(int value) {
	Node* temp = head;
	int position = 1;

	while (temp != nullptr) {
		if (temp->data == value) {
			cout << "Element found at position: " << position << endl;
			return;
		}
		temp = temp->next;
		position++;
	}

	cout << "Element not found.\n";
}

void display() {
	Node* temp = head;

	if (temp == nullptr) {
		cout << "List is empty.\n";
		return;
	}

	cout << "List: ";
	while (temp != nullptr) {
		cout << temp->data << " -> ";
		temp = temp->next;
	}
	cout << "NULL\n";
}

int main() {
	int choice, value, position;

	do {
		cout << "\n--- MENU ---\n";
		cout << "1. Insert at position\n";
		cout << "2. Delete at position\n";
		cout << "3. Search element\n";
		cout << "4. Count nodes\n";
		cout << "5. Display list\n";
		cout << "6. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Enter value: ";
			cin >> value;
			cout << "Enter position: ";
			cin >> position;
			insertAtPosition(value, position);
			break;

		case 2:
			cout << "Enter position to delete: ";
			cin >> position;
			deleteAtPosition(position);
			break;

		case 3:
			cout << "Enter value to search: ";
			cin >> value;
			searchElement(value);
			break;

		case 4:
			cout << "Total nodes: " << countNodes() << endl;
			break;

		case 5:
			display();
			break;

		case 6:
			cout << "Exiting program...\n";
			break;

		default:
			cout << "Invalid choice!\n";
		}

	} while (choice != 6);

	return 0;
}
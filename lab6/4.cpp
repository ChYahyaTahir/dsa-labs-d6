#include <iostream>
using namespace std;

// Node structure for Patient
struct Node {
	string name;
	Node* next;
};

Node* head = nullptr;
void addPatient(string name) {
	Node* newNode = new Node;
	newNode->name = name;
	newNode->next = nullptr;

	if (head == nullptr) {
		head = newNode;
	}
	else {
		Node* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = newNode;
	}

	cout << name << " added to the queue.\n";
}

)
void removePatient(string name) {
	if (head == nullptr) {
		cout << "Queue is empty.\n";
		return;
	}

	Node* temp = head;
	Node* prev = nullptr;

	// If first patient cancels
	if (temp->name == name) {
		head = temp->next;
		delete temp;
		cout << name << " removed from the queue.\n";
		return;
	}

	while (temp != nullptr && temp->name != name) {
		prev = temp;
		temp = temp->next;
	}

	if (temp == nullptr) {
		cout << "Patient not found.\n";
		return;
	}

	prev->next = temp->next;
	delete temp;
	cout << name << " removed from the queue.\n";
}

void displayQueue() {
	if (head == nullptr) {
		cout << "No patients in queue.\n";
		return;
	}

	Node* temp = head;
	cout << "Patient Queue: ";
	while (temp != nullptr) {
		cout << temp->name << " -> ";
		temp = temp->next;
	}
	cout << "NULL\n";
}

int countPatients() {
	int count = 0;
	Node* temp = head;

	while (temp != nullptr) {
		count++;
		temp = temp->next;
	}
	return count;
}

int main() {
	// Adding patients
	addPatient("Ali");
	addPatient("Sara");
	addPatient("Ahmed");
	addPatient("Fatima");

	displayQueue();

	// Removing a patient
	removePatient("Ahmed");

	displayQueue();

	// Count patients
	cout << "Total patients in queue: " << countPatients() << endl;

	// Another removal
	removePatient("Ali");

	displayQueue();

	cout << "Total patients in queue: " << countPatients() << endl;

	return 0;
}
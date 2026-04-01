#include <iostream>
using namespace std;

// Node structure
class Node {
public:
	int data;
	Node* next;

	Node(int value) {
		data = value;
		next = nullptr;
	}
};

class LinkedList {
private:
	Node* head;

public:
		LinkedList() {
		head = nullptr;
	}

	// Insert at beginning
	void insertAtBeginning(int value) {
		Node* newNode = new Node(value);
		newNode->next = head;
		head = newNode;
	}

		void insertAtEnd(int value) {
		Node* newNode = new Node(value);

		if (head == nullptr) {
			head = newNode;
			return;
		}

		Node* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}

		temp->next = newNode;
	}

	
	void deleteByValue(int value) {
		if (head == nullptr) {
			cout << "List is empty.\n";
			return;
		}

				if (head->data == value) {
			Node* temp = head;
			head = head->next;
			delete temp;
			cout << "Node deleted.\n";
			return;
		}

		Node* temp = head;
		Node* prev = nullptr;

		while (temp != nullptr && temp->data != value) {
			prev = temp;
			temp = temp->next;
		}

		if (temp == nullptr) {
			cout << "Value not found.\n";
			return;
		}

		prev->next = temp->next;
		delete temp;
		cout << "Node deleted.\n";
	}

		void display() {
		Node* temp = head;

		if (temp == nullptr) {
			cout << "List is empty.\n";
			return;
		}

		cout << "Linked List: ";
		while (temp != nullptr) {
			cout << temp->data << " -> ";
			temp = temp->next;
		}
		cout << "NULL\n";
	}
};


int main() {
	LinkedList list;

	list.insertAtBeginning(30);
	list.insertAtBeginning(10);
	list.insertAtEnd(50);
	list.insertAtEnd(70);

	list.display();

	list.deleteByValue(50);
	list.display();

	return 0;
}
#include <iostream>
using namespace std;

struct Node {
	string name;
	int priority; // Higher value = higher priority
	Node* next;
};

class BookQueue {
private:
	string bookName;
	Node* head;

public:

	BookQueue(string name) {
		bookName = name;
		head = nullptr;
	}

	
	void addStudent(string name, int priority) {
		Node* newNode = new Node{ name, priority, nullptr };

				if (head == nullptr || priority > head->priority) {
			newNode->next = head;
			head = newNode;
		}
		else {
			Node* temp = head;

			// Find correct position
			while (temp->next != nullptr && temp->next->priority >= priority) {
				temp = temp->next;
			}

			newNode->next = temp->next;
			temp->next = newNode;
		}

		cout << name << " added to \"" << bookName << "\" queue.\n";
	}

		void removeStudent(string name) {
		if (head == nullptr) {
			cout << "Queue is empty.\n";
			return;
		}

		Node* temp = head;
		Node* prev = nullptr;

		if (temp->name == name) {
			head = temp->next;
			delete temp;
			cout << name << " removed from \"" << bookName << "\" queue.\n";
			return;
		}

		while (temp != nullptr && temp->name != name) {
			prev = temp;
			temp = temp->next;
		}

		if (temp == nullptr) {
			cout << "Student not found.\n";
			return;
		}

		prev->next = temp->next;
		delete temp;
		cout << name << " removed from \"" << bookName << "\" queue.\n";
	}

		void updatePriority(string name, int newPriority) {
		removeStudent(name);
		addStudent(name, newPriority);
		cout << name << "'s priority updated.\n";
	}

		void display() {
		cout << "\nReservation list for \"" << bookName << "\":\n";

		if (head == nullptr) {
			cout << "No reservations.\n";
			return;
		}

		Node* temp = head;
		while (temp != nullptr) {
			cout << temp->name << " (Priority: " << temp->priority << ") -> ";
			temp = temp->next;
		}
		cout << "NULL\n";
	}

		int countStudents() {
		int count = 0;
		Node* temp = head;

		while (temp != nullptr) {
			count++;
			temp = temp->next;
		}
		return count;
	}

		void serveNext() {
		if (head == nullptr) {
			cout << "No students waiting.\n";
			return;
		}

		Node* temp = head;
		cout << temp->name << " has been served for \"" << bookName << "\".\n";
		head = head->next;
		delete temp;
	}
};

int main() {
	// Two books
	BookQueue book1("Data Structures");
	BookQueue book2("Operating Systems");

	// Add students
	book1.addStudent("Ali", 2);
	book1.addStudent("Sara", 3);
	book1.addStudent("Ahmed", 1);

	book2.addStudent("Fatima", 2);
	book2.addStudent("Usman", 1);
	book2.addStudent("Zara", 3);

	// Display queues
	book1.display();
	book2.display();

	// Update priority
	book1.updatePriority("Ahmed", 4);

	// Remove student
	book2.removeStudent("Usman");

	// Display again
	book1.display();
	book2.display();

	// Count students
	cout << "\nTotal in Data Structures: " << book1.countStudents() << endl;
	cout << "Total in Operating Systems: " << book2.countStudents() << endl;

	// Serve next student (book returned)
	book1.serveNext();
	book2.serveNext();

	// Final display
	book1.display();
	book2.display();

	return 0;
}
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

// Insert at beginning
void insertBeg() {
    Node* newNode = new Node;
    cout << "Enter value: ";
    cin >> newNode->data;

    newNode->prev = NULL;
    newNode->next = head;

    if(head != NULL)
        head->prev = newNode;

    head = newNode;

    cout << "Inserted at beginning\n";
}

// Insert at end
void insertEnd() {
    Node* newNode = new Node;
    cout << "Enter value: ";
    cin >> newNode->data;
    newNode->next = NULL;

    if(head == NULL) {
        newNode->prev = NULL;
        head = newNode;
    } else {
        Node* temp = head;
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    cout << "Inserted at end\n";
}

// Delete from beginning
void deleteBeg() {
    if(head == NULL) {
        cout << "List is empty\n";
    } else {
        Node* temp = head;
        cout << "Deleted: " << temp->data << endl;

        head = head->next;

        if(head != NULL)
            head->prev = NULL;

        delete temp;
    }
}

// Delete from end
void deleteEnd() {
    if(head == NULL) {
        cout << "List is empty\n";
    } else if(head->next == NULL) {
        cout << "Deleted: " << head->data << endl;
        delete head;
        head = NULL;
    } else {
        Node* temp = head;
        while(temp->next != NULL)
            temp = temp->next;

        cout << "Deleted: " << temp->data << endl;
        temp->prev->next = NULL;
        delete temp;
    }
}

// Display list
void display() {
    if(head == NULL) {
        cout << "List is empty\n";
    } else {
        Node* temp = head;
        cout << "List: ";
        while(temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n--- DOUBLY LINKED LIST MENU ---\n";
        cout << "1. Insert at Beginning\n2. Insert at End\n";
        cout << "3. Delete from Beginning\n4. Delete from End\n";
        cout << "5. Display\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: insertBeg(); break;
            case 2: insertEnd(); break;
            case 3: deleteBeg(); break;
            case 4: deleteEnd(); break;
            case 5: display(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice\n";
        }

    } while(choice != 6);

    return 0;
}
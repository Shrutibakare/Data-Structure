#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Insert at beginning
void insertBeg() {
    Node* newNode = new Node;
    cout << "Enter value: ";
    cin >> newNode->data;

    newNode->next = head;
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
        head = newNode;
    } else {
        Node* temp = head;
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    cout << "Inserted at end\n";
}

// Delete from beginning
void deleteBeg() {
    if(head == NULL) {
        cout << "List is empty\n";
    } else {
        Node* temp = head;
        cout << "Deleted: " << head->data << endl;
        head = head->next;
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
        while(temp->next->next != NULL)
            temp = temp->next;

        cout << "Deleted: " << temp->next->data << endl;
        delete temp->next;
        temp->next = NULL;
    }
}

// Search element
void search() {
    int key, pos = 1;
    cout << "Enter value to search: ";
    cin >> key;

    Node* temp = head;
    while(temp != NULL) {
        if(temp->data == key) {
            cout << "Element found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }

    cout << "Element not found\n";
}

// Display list
void display() {
    if(head == NULL) {
        cout << "List is empty\n";
    } else {
        Node* temp = head;
        cout << "List: ";
        while(temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n--- SINGLY LINKED LIST MENU ---\n";
        cout << "1. Insert at Beginning\n2. Insert at End\n";
        cout << "3. Delete from Beginning\n4. Delete from End\n";
        cout << "5. Search\n6. Display\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: insertBeg(); break;
            case 2: insertEnd(); break;
            case 3: deleteBeg(); break;
            case 4: deleteEnd(); break;
            case 5: search(); break;
            case 6: display(); break;
            case 7: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice\n";
        }

    } while(choice != 7);

    return 0;
}
#include <iostream>
using namespace std;

#define MAX 5

int stackArr[MAX];
int top = -1;


void display() {
    if (top == -1) {
        cout << "Stack is empty." << endl;
        return;
    }

    cout << "Current Stack: ";
    for (int i = top; i >= 0; i--) {
        cout << stackArr[i] << " ";
    }
    cout << endl;
}


void push(int value) {
    if (top == MAX - 1) {
        cout << "Stack Overflow! Cannot push." << endl;
    } else {
        stackArr[++top] = value;
        cout << value << " pushed into stack." << endl;
    }
    display();   
}

void pop() {
    if (top == -1) {
        cout << "Stack Underflow! Cannot pop." << endl;
    } else {
        cout << stackArr[top--] << " popped from stack." << endl;
    }
    display();   
}

int main() {
    int choice, value;

    do {
        cout << "\n1. Push\n2. Pop\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 3);

    return 0;
}
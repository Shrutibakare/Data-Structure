#include <iostream>
using namespace std;

int queue[5];
int front = -1, rear = -1;

int main() {
    int choice, value;

    do {
        cout << "\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice) {

            case 1: 
                if (rear == 4) {
                    cout << "Queue Overflow";
                } else {
                    cout << "Enter element: ";
                    cin >> value;
                    if (front == -1)
                        front = 0;
                    rear++;
                    queue[rear] = value;
                }
                break;

            case 2: 
                if (front == -1 || front > rear) {
                    cout << "Queue Underflow";
                } else {
                    cout << "Deleted element: " << queue[front];
                    front++;
                }
                break;

            case 3:
                if (front == -1 || front > rear) {
                    cout << "Queue is empty";
                } else {
                    cout << "Queue elements: ";
                    for (int i = front; i <= rear; i++) {
                        cout << queue[i] << " ";
                    }
                }
                break;

            case 4:
                cout << "Exit";
                break;

            default:
                cout << "Invalid choice";
        }

    } while(choice != 4);

    return 0;
}
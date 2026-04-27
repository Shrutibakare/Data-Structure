#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};

Node* top=NULL;

void push(){
    Node* newNode = new Node;
    cout<<"Enter value: ";
    cin>> newNode->data;
    newNode->next = top;
    top = newNode;
        cout << "Element pushed\n";

}
void pop(){
    if(top == NULL){
        cout<<"Stack underflow";
    }else{
        Node* temp = top;
        cout<<"Popped Element :"<<top->data<<endl;
        top=top->next;
        delete temp;
    }
}
void display(){
    if(top == NULL){
        cout<<"Stack is Empty";
    }else{
        Node* temp=top;
        cout<<"Stack Elements:";
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
}

int main(){
    int choice;
    do {
        cout << "\n--- STACK MENU ---\n";
        cout << "1. Push\n2. Pop\n3. Display\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice\n";
        }
    } while(choice != 4);

    return 0;

}
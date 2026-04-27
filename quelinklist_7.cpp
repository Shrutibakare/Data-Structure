#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node *front=NULL,*rear=NULL;


void enqueue(){
Node* newNode = new Node;
cout<<"Enter value";
cin>>newNode->data;
newNode->next = NULL;
if(front==NULL){
    front = rear = newNode;
}else{
    rear->next = newNode;
    rear = newNode;
}
    cout << "Element inserted\n";

}
void dequeue(){
    if(front==NULL){
        cout<<"Queue Underflow\n";
    }else{
        Node* temp=front;
        cout<<"Deleted Element:"<<front->data<<endl;
        front=front->next;
        delete temp;
    }
}

void display(){
    if(front == NULL){
        cout<<"Queue is Empty";
    }else{
        Node* temp=front;
        cout<<"Queue elements:";
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
}

int main(){
    int choice;
    do {
        cout << "\n--- QUEUE MENU ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice\n";
        }
    } while(choice != 4);

}
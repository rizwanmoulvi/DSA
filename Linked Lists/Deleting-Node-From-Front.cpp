#include <bits/stdc++.h>

using namespace std;

// Creating a class for Node object and defining it's properties.
class Node{
    public:
        int data;
        Node* nextNodeAddress;
    
    // Initializing the object using constructor to default values
    Node(int value){
        data = value;
        nextNodeAddress = nullptr;
    }
};

// Creating a class for linked list
class LinkedList{
    public:
    Node* head; //Creating the first node which is head in the linkedlist

    //Initializing the head node of Linked List using constructor
    LinkedList(){
        head = nullptr;
    }

    //Function to add nodes in front of the head node in linked list
    void addNodeInFront(int value){

        //Creating a new node and passing value to node for data
        Node* newNode = new Node(value);

        //If the head node is pointing to null pointer then the new node is considered as the head node (in case of empty linked list)
        if(head == nullptr){
            head = newNode;
        }

        //If the linked list is not empty then the pointer in the new node points to head node and the new node becomes head node
        else{
            newNode->nextNodeAddress = head;
            head = newNode;
        }
    }

    //function to delete node from from of the Linked list
    void deleteNodeFromFront(){
        //Creating a Node "temp" which points to head node of the linked List
        Node* temp = head;
        //if the linked list is empty then show message
        if(head == nullptr){
            cout<<"List is Empty"<<endl;
        }
        //if linked list is not empty then change the head node by changing the pointer to node before head node and delete node temp to free memory
        else{
            head = head->nextNodeAddress;
            delete temp;
        }
    }

    //function to print values of nodes in linked list
    void display(){
        //Creating a node called current and pointing it to head node
        Node* current = head; 
        //Running a while loop to print values with condition that current pointer doesn't point to nullptr
        while(current != nullptr){
            cout<<current->data<<" ";
            //pointing the current pointer to the next node
            current = current->nextNodeAddress;
        }
        cout<<endl;
    }
};

int main(){
    LinkedList l1;
    l1.addNodeInFront(50);
    l1.addNodeInFront(40);
    l1.addNodeInFront(30);
    l1.addNodeInFront(20);
    l1.addNodeInFront(10);
    cout<<"Original Linked List"<<endl;
    l1.display();
    l1.deleteNodeFromFront();
    cout<<"Linked List After Deleting Node From Front"<<endl;
    l1.display();
    
    return 0;
}
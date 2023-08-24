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

    void deleteNodeFromEnd(){
        //If the linked list is empty the print the message
        if(head == nullptr){
            cout<<"Linked List is empty"<<endl;
        }
        //If the linked list has just one node by checking if the nextnodeaddress stored in node is pointing to nullptr
        if(head->nextNodeAddress == nullptr){
            delete head;
            //pointing head to nullptr to free memory
            head = nullptr; 
        }

        //If the the linked list has more than one node
        //creating to pointers one pointing to nullptr and another to pointing to head
        Node* previous = nullptr;
        Node* current = head;

        //loop to traverse to the last node of the linked list
        while(current->nextNodeAddress != nullptr){
            previous = current;
            current = current->nextNodeAddress;
        }
        //making previous pointer point to null ptr and making it last node and then deleteing the currrent node
        previous->nextNodeAddress = nullptr;
        delete current;
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
    l1.deleteNodeFromEnd();
    cout<<"Linked List After Deleting Node From End"<<endl;
    l1.display();
    
    return 0;
}
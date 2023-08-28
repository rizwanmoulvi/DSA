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

    //Function to find the middle node of the linked list
    void findMiddleNode(){
        //Creating two pointers to traverse the linked list
        Node* fast = head;
        Node* slow = head;
        //Running a while loop till the fast pointer reaches the end of the linked list
        while(fast != NULL && fast->nextNodeAddress != NULL){
            //moving the slow pointer by one node
            slow = slow->nextNodeAddress;
            //moving the fast pointer by two nodes
            fast = fast->nextNodeAddress->nextNodeAddress;
        }
        cout<<slow->data<<endl;
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
    l1.addNodeInFront(70);
    l1.addNodeInFront(60);
    l1.addNodeInFront(50);
    l1.addNodeInFront(40);
    l1.addNodeInFront(30);
    l1.addNodeInFront(20);
    l1.addNodeInFront(10);
    cout<<"Linked List"<<endl;
    l1.display();
    cout<<"Middle Node Of The Linked List"<<endl;
    l1.findMiddleNode();
    
    return 0;
}
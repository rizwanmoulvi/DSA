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

    //function to add node at specified location that takes value of newnode and value of node after which the new node will be added
    void insertNodeAtSpecficLocation(int value, int addAfter){
        //Creating a newnode to add 
        Node* newNode = new Node(value);
        //creating three pointer to maintain the track and mapping each them together
        Node* previous = nullptr;
        Node* current = head;
        Node* next = current->nextNodeAddress;
        //loop to traverse to the desired location
        while(head != nullptr){
            //if the value the current node matches with the specified location then add the node and change mapping and break loop
            if(current->data == addAfter){
                previous = current;
                //pointing current to new node 
                current = newNode;
                //pointing new node to next node
                current->nextNodeAddress = next;
                //pointing previous node new node
                previous->nextNodeAddress = current;
                break;
            }
            //condition doesn't matches then change the mapping and continue traversing
            previous = current;
            current = next;
            next = next->nextNodeAddress;
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
    l1.addNodeInFront(20);
    l1.addNodeInFront(10);
    cout<<"Original Linked List"<<endl;
    l1.display();
    cout<<"Linked List After Adding Node At Specified Location"<<endl;
    l1.insertNodeAtSpecficLocation(30,20);
    l1.display();
    
    return 0;
}

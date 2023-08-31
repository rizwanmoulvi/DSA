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

    //function to merge to linked lists
    void merge(LinkedList& l2){
        //If the second list is empty then we can't do anything
        if(!l2.head){
            return;
        }
        //If the first list is empty then the head of the first list will be pointed to head of second list
        if(!head){
            head = l2.head;
        }
        //To traverse to the last node of the first first list
        else{
            Node* current = head;
            while(current->nextNodeAddress){
                current = current->nextNodeAddress;
            }
            //Pointing the address in last node to the head of the second list
            current->nextNodeAddress = l2.head;
        }
        //Making head of second list nullptr so that it should not delete it's Nodes
        l2.head = nullptr;
    }

    //First came accross the concept of destructors to free memory when linked list is not needed
    ~LinkedList(){
        Node* current = head;
        while(current){
            Node* next = current->nextNodeAddress;
            delete current;
            current = next;
        }
    }

};

int main(){
    LinkedList l1, l2;
    l1.addNodeInFront(50);
    l1.addNodeInFront(40);
    l1.addNodeInFront(30);
    l1.addNodeInFront(20);
    l1.addNodeInFront(10);

    l2.addNodeInFront(100);
    l2.addNodeInFront(90);
    l2.addNodeInFront(80);
    l2.addNodeInFront(70);
    l2.addNodeInFront(60);

    cout<<"Linked List 1"<<endl;
    l1.display();

    cout<<"Linked List 2"<<endl;
    l2.display();

    cout<<"Merged Linked List"<<endl;
    l1.merge(l2);
    l1.display();
    
    return 0;
}

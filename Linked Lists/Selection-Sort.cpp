#include <bits/stdc++.h>

using namespace std;

// Creating a class for Node object and defining it's properties.
class Node
{
public:
    int data;
    Node *nextNodeAddress;

    // Initializing the object using constructor to default values
    Node(int value)
    {
        data = value;
        nextNodeAddress = nullptr;
    }
};

// Creating a class for linked list
class LinkedList
{
public:
    Node *head; // Creating the first node which is head in the linkedlist

    // Initializing the head node of Linked List using constructor
    LinkedList()
    {
        head = nullptr;
    }

    // Function to add nodes in front of the head node in linked list
    void addNodeInFront(int value)
    {

        // Creating a new node and passing value to node for data
        Node *newNode = new Node(value);

        // If the head node is pointing to null pointer then the new node is considered as the head node (in case of empty linked list)
        if (head == nullptr)
        {
            head = newNode;
        }

        // If the linked list is not empty then the pointer in the new node points to head node and the new node becomes head node
        else
        {
            newNode->nextNodeAddress = head;
            head = newNode;
        }
    }

    // function to print values of nodes in linked list
    void display()
    {
        // Creating a node called current and pointing it to head node
        Node *current = head;
        // Running a while loop to print values with condition that current pointer doesn't point to nullptr
        while (current != nullptr)
        {
            cout << current->data << " ";
            // pointing the current pointer to the next node
            current = current->nextNodeAddress;
        }
        cout << endl;
    }

    //function to sort a linked list using selection sort algorithm
    void selectionSort(){
        //checking if the linked list is empty or not
        if(head == nullptr){
            cout<<"Linked List List Empty"<<endl;
        }
        //creating a pointer that points to the head node of the linked list
        Node* current = head;
        //creating a while loop to transverse the linked list once
        while(current->nextNodeAddress != nullptr){
            //creating a node called minValue to store the node with mimimum value 
            Node* minValue = current;
            //creating a node that transverse the linked list starting from current + 1 node
            Node* temp = current->nextNodeAddress;
            //a loop to transverse the linked list 
            while (temp->nextNodeAddress != nullptr){
                //condition to check if the value the temp Node is less than the current node value and if true then swap the nodes
                if (temp->data < minValue->data){
                    minValue = temp;
                }
                //pointing temp node to next node
                temp= temp->nextNodeAddress;
            }

            //swapping values, the minValue is added to current node and current node value is added to minValue node
            int temp2 = current->data;
            current->data = minValue->data;
            minValue->data = temp2;
            //pointing current node to next node
            current = current->nextNodeAddress;
        }

    }
};

int main()
{
    LinkedList l1;
    l1.addNodeInFront(50);
    l1.addNodeInFront(80);
    l1.addNodeInFront(0);
    l1.addNodeInFront(30);
    l1.addNodeInFront(70);
    l1.addNodeInFront(19);
    l1.addNodeInFront(33);
    l1.addNodeInFront(77);
    l1.addNodeInFront(10);
    l1.addNodeInFront(44);
    l1.addNodeInFront(87);
    l1.addNodeInFront(15);

    cout << "Original Linked List " << endl;
    l1.display();
    cout << endl;
    cout << "Sorted Linked List" << endl;
    l1.selectionSort();
    l1.display();
    return 0;
}
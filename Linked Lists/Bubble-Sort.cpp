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

    // Function to calculate the length of the Linked List to iterate the bubble sort loop that many times
    int len()
    {
        Node *current = head;
        int i = 1;
        while (current->nextNodeAddress != nullptr)
        {
            i++;
            current = current->nextNodeAddress;
        }
        return i;
    }

    // Bubble Sort function to sort the linked list in ascending order, only swapping values not nodes
    void bubblesort()
    {
        int length = len();
        // a for loop to iterate over linked list, length of linked list times
        for (int i = 0; i <= length; i++)
        {
            Node *current = head;
            // a while loop to iterate over linked list and swap values
            while (current->nextNodeAddress != nullptr)
            {
                // condition to check if the given the value at current node is less than next node value
                if (current->data >= current->nextNodeAddress->data)
                {
                    // Performing swapping
                    int temp = current->data;
                    current->data = current->nextNodeAddress->data;
                    current->nextNodeAddress->data = temp;
                }
                // pointing current node to next node
                current = current->nextNodeAddress;
            }
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
    l1.addNodeInFront(10);

    cout << "Original Linked List " << endl;
    l1.display();
    cout << endl;
    cout << "Sorted Linked List" << endl;
    l1.bubblesort();
    l1.display();
    return 0;
}
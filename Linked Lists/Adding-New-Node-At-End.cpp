#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
        int data;
        Node* nextNodeAddress;
    Node(int value){
        data = value;
        nextNodeAddress = nullptr;
    }
};

class LinkedList{
    public:
    Node* head;
    LinkedList(){
        head = nullptr;
    }

    void addNodeAtEnd(int value){
        Node* newNode = new Node(value);
        if(head == nullptr){
            head = newNode;
        }
        else{
            Node* current = head;
            while(current->nextNodeAddress != nullptr){
                current = current->nextNodeAddress;
            }
            current->nextNodeAddress = newNode;
        }
    }

    void display(){
        Node* current = head;
        while(current != nullptr){
            cout<<current->data<<" ";
            current = current->nextNodeAddress;
        }
        cout<<endl;
    }
};

int main(){
    LinkedList l1;
    l1.addNodeAtEnd(10);  
    l1.addNodeAtEnd(20);  
    l1.addNodeAtEnd(30);  
    l1.addNodeAtEnd(40);  
    l1.addNodeAtEnd(50);
    l1.display();  
    return 0;
}
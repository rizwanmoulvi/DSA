#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
        int data;
        Node* nextNodeAddres;

    Node(int value){
        data = value;
        nextNodeAddres = nullptr;
    }
};

class LinkedList{
    public:
    Node* head;

    LinkedList(){
        head = nullptr;
    }

    void addNode(int value){
        Node* newNode = new Node(value);
        if(head == nullptr){
            head = newNode;
        }
        else {
            newNode->nextNodeAddres = head;
            head = newNode;
        }
    }

    void display(){
        Node* current = head;
        while(current != nullptr){
            cout<<current->data<<" ";
            current = current->nextNodeAddres;
        }
        cout<<endl;
    }

};

int main(){
    LinkedList l1;
    l1.addNode(60);
    l1.addNode(50);
    l1.addNode(40);
    l1.addNode(30);
    l1.addNode(20);
    l1.addNode(10);
    l1.display();
    return 0;
}
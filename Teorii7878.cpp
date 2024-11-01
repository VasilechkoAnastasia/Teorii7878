#include <iostream>
using namespace std;

class Node 
{
public:
    int data; 
    Node* next; 
    Node(int value) : data(value), next(nullptr) {} 
};

class SinglyLinkedList 
{
    Node* head; 

public:
    SinglyLinkedList() : head(nullptr) {} 

    ~SinglyLinkedList() 
    {
        Node* current = head;
        Node* nextNode;

        while (current != nullptr) 
        {
            nextNode = current->next; 
            delete current; 
            current = nextNode; 
        }
    }

    void append(int value) 
    {
        Node* newNode = new Node(value);
        if (head == nullptr) 
        {
            head = newNode; 
        }
        else 
        {
            Node* temp = head;
            while (temp->next != nullptr) 
            {
                temp = temp->next; 
            }
            temp->next = newNode; 
        }
    }

    void print() const 
    {
        Node* temp = head;
        while (temp != nullptr) 
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() 
{
    SinglyLinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    cout << "list: ";
    list.print();;
}
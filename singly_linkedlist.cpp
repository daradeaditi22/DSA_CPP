#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void insert(int val) {
        Node* p = new Node(val); 
        if (head == NULL) {
            head = p;
        } else {
            Node* q = head;
            while (q->next != NULL) {
                q = q->next;
            }
            q->next = p;
        }
    }

       void remove(int val) {
        Node* p = NULL;
        Node* q = head;

        if (q!=NULL && q->data == val) {
            p = head;
            head = head->next;
            delete p;
            return;
        }

        while (q->next != NULL) {
            if (q->next->data == val) {
                p = q->next;
                q->next = p->next;
                delete p;
                return;
            }
            q = q->next;
        }

        cout <<endl<< "Value " << val << " not found in the list.\n";
    }

    void display() {
        cout<<endl<<"Linked List ";
        Node* q = head;
        while (q != NULL) {
            cout << q->data << " -> ";
            q = q->next;
        }
    }
};

int main() {
    LinkedList list;

    list.insert(5);
    list.insert(15);
    list.insert(25);
    list.display();
    
    list.insert(35);
    list.insert(45);
    list.insert(55);
    list.display();
    
    list.remove(35);
    list.display(); 

    list.remove(55); 
    list.display();

    list.remove(100); 
    list.display();

    return 0;
}
/*
PS D:\Darade Aditi 121> & "D:\Darade Aditi 121\singly_linkedlist.exe"

Linked List 5 -> 15 -> 25 -> 
Linked List 5 -> 15 -> 25 -> 35 -> 45 -> 55 -> 
Linked List 5 -> 15 -> 25 -> 45 -> 55 -> 
Linked List 5 -> 15 -> 25 -> 45 -> 
Value 100 not found in the list.

Linked List 5 -> 15 -> 25 -> 45 -> 
PS D:\Darade Aditi 121> 
*/
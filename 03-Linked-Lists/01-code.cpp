#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void deleteAtStart(Node*& head){
    if(head == nullptr) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteAtEnd(Node*& head){
    if(head == nullptr) return;
    Node* temp = head;

    if(head->next == nullptr){
        delete head;
        head = nullptr;
        return;
    }

    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

void DeleteValue(Node*& head, int val){
    if(head == nullptr) return;
    if(head->data == val){
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* temp = head;
    while(temp->next != nullptr && temp->next->data != val){
        temp = temp->next;
    }
     if (temp->next == nullptr) return;
     Node* toDelete = temp->next;
     temp->next = temp->next->next;
     delete toDelete;
}
void insertAtStart(Node*& head, int val) {
    Node* newNode = new Node{val, head};
    head = newNode;
}

void insertAtEnd(Node*& head, int val) {
    Node* newNode = new Node{val, nullptr};
    if(head == nullptr){
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(Node* head){
    while(head != nullptr){
        cout << head->data << " ";
        head = head->next;
    }
}

int main(){
    Node* head = nullptr;

    insertAtStart(head, 30);
    insertAtStart(head, 20);
    insertAtStart(head, 10);

    insertAtEnd(head, 40);
    insertAtEnd(head, 50);
    insertAtEnd(head, 60);

    printList(head);
    cout << endl;

    deleteAtStart(head);
    printList(head);    
    cout << endl;
    
    deleteAtEnd(head);
    printList(head);
    cout << endl;

    DeleteValue(head, 30);
    printList(head);
    cout << endl;

    return 0;
}
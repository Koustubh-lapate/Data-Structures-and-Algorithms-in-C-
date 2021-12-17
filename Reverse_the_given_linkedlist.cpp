#include <iostream>
using namespace std;

class Linkedlist{
    struct Node{
        int data;
        Node*next;
        Node(int d){
            data = d;
            next = NULL;
        }
    };
    Node *head, *tail;
    
public:
    Linkedlist(){
        head = NULL;
        tail = NULL;
    }
    
    void insertatend(int data){
        Node* newNode = new Node(data);
        
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = tail->next;
        }
    }
    
    void print(){
        if(head == NULL){
            cout<<"Empty Linkedlist\n";
            return;
        }
        else{
            Node* current = head;
            while(current!=NULL){
                cout<<current->data<<"->";
                current = current->next;
            }
            cout<<"NULL\n";
        }
    }
    
    void reverselliterative(){
        Node *prev = NULL, *current = head, *next = NULL;
        
        while(current!=NULL){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
};

int main(){
    Linkedlist l = Linkedlist();
    l.insertatend(0);
    l.insertatend(1);
    l.insertatend(2);
    l.insertatend(3);
    l.insertatend(4);
    l.print();
    l.reverselliterative();
    l.print();
    return 0;
}    

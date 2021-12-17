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
    
    void deleteNode(int dataToDel){
        Node* current = head;
        if(head == NULL){
            cout<<"Linkedlist is Empty"<<endl;
            return;
        }
        else if(head->data == dataToDel){
            head = head->next;
            free(current);
            return;
        }
        else{
            while(current->next!=NULL && current->next->data!=dataToDel){
                current = current->next;
            }
            if(current->next == NULL){
                cout<<"Data does not exist\n";
                return;
            }
            else{
                Node* nodeToDel = current->next;
                current->next = current->next->next;
                free(nodeToDel);
            }
        }
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
    l.deleteNode(0);
    l.print();
    l.deleteNode(2);
    l.print();
    l.deleteNode(4);
    l.print();
    return 0;
}    

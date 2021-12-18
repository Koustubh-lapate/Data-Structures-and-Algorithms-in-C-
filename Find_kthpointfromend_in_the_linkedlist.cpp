#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int d){
        data = d;
        next = NULL;
    }
};

class Linkedlist{
    Node *head;
    
public:
    Linkedlist(){
        head = NULL;
    }
    
    void insertatend(int data){
        Node *newNode = new Node(data);
        
        if(head == NULL){
            head = newNode;
        }
        else{
            Node* current = head;
            while(current->next!=NULL){
                current = current->next;
            }
            current->next = newNode;
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
    
    Node *findKthfromend(int k){
        Node *slow = head, *fast = head;
        while(--k){
            fast = fast->next;
        }
        fast = fast->next;
        while(fast!=NULL){
           fast = fast->next;
           slow = slow->next;
        }
        return slow;
    }
    
};

int main() {
    Linkedlist l = Linkedlist();
    l.insertatend(0);
    l.insertatend(1);
    l.insertatend(2);
    l.insertatend(3);
    l.insertatend(4);
    l.print();
    Node* kth = l.findKthfromend(2);
    cout<<kth->data<<endl;
	return 0;
}

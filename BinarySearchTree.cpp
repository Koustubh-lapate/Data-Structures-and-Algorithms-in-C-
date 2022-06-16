#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node{
	public:
	int data;
	Node *left;
	Node *right;
	
	Node(int d){
		this->data = d;
		this->left = NULL;
		this->right = NULL;
	}
};

Node *insertIntoBST(Node * &root, int d){
	//base case
	if(root == NULL){
		root = new Node(d);
		return root;
	}
		
	if(d > root->data){
		root->right = insertIntoBST(root->right, d);
	}
	else{
		root->left = insertIntoBST(root->left, d);
	}
		
	return root;
}

void takeInput(Node * &root){
	int data;
	cin >> data;
		
	while(data != -1){
		root = insertIntoBST(root, data);
		cin >> data;
	}
}

Node *minVal(Node *root){
	Node *temp = root;
	
	while(temp->left != NULL){
		temp = temp->left;
	}
	
	return temp;
}

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child ndoes
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }

}

int main() {
	// Your code goes here;
	Node *root = NULL;
	cout << "Enter data to create BST:" << endl;
	takeInput(root);
	
	cout << "Printing the BST" << endl;
	levelOrderTraversal(root);
	
	return 0;
}

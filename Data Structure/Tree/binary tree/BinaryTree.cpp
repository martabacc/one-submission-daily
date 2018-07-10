#include<bits/stdc++.h>
using namespace std;

struct Node{
	int val;
	struct Node* left,
		  * right;
};

Node* newNode(int val){
	Node * temp  = new Node();
	temp->val = val;
	temp->left = temp->right = NULL;
	return temp;
}

Node* lca(struct Node * node, int key1, int key2)
{
	if(node == NULL) return NULL;
	
	if(node->val==key1 || node->val==key2) return node;
	
	Node *left = lca(node->left, key1, key2);
	Node *right = lca(node->right, key1, key2);
	
	if(left && right) return node;
	else{
		return left!=NULL ? left : right;
	}
	
}

int main()
{
	Node * root = newNode(1);;
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    
    Node * result = lca(root, 10,11);
    
    if(result != NULL) cout << result->val << endl;
    else cout << "Tidak ketemu" << endl;
	
	
}



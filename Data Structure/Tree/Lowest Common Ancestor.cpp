#include<bits/stdc++.h>
using namespace std;
// please delete after
// BC-<order>-<topic>-RIGHT(10, TopicTitle)
// IM-<order>-<topic>-RIGHT(10, TopicTitle)
// SJ-<Name of OJ>-ProblemCode

struct Node{
	int val;
	struct Node* left,
		  * right;
};

bool newNode(int val){
	Node * temp  = new Node();
	temp->val = val;
	temp->left = temp->right = NULL;
	return temp;
}

void insertBst(Node* node, int val){
	
	if(node->val==val) return node; //return reference if duplicate
	
	if( node->val < val ){
		if( node->left !=NULL ) 
			return insertNewNode(node->left, val);
		
		node->left = newNode(val);
	}
	else if( node->val > val ){
		if( node->left !=NULL ) 
			return insertNewNode(node->right, val);
		node->right = newNode(val);
	}
	
	return node->val < val ? node->left : node->right;
	
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
	//testing
	Node * root = newNode(1);;
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    
	return 0;
}




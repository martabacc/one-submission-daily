#include<bits/stdc++.h>
using namespace std;
// please delete after
// BC-<order>-<topic>-RIGHT(10, TopicTitle)
// IM-<order>-<topic>-RIGHT(10, TopicTitle)
// SJ-<Name of OJ>-ProblemCode

struct Node{
	int data;
	struct Node* left,
		  * right;
};
Node* newNode(int val){
	Node * temp  = new Node();
	temp->data = val;
	temp->left = temp->right = NULL;
	return temp;
}

/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
   struct Node {
      int data;
      Node* left;
      Node* right;
   }
*/
   bool validatePath(int value, vector< pair<int, bool> > path )
   {
       // false means left child, true otherwise
       bool leftNow = false;
       for(int x=0;x<path.size();x++){
           
           if(path[x].second) leftNow = value > path[x].first ? false:true;
           else leftNow = value < path[x].first ? false:true;
           
           if(leftNow) return false;
       }
       return true;
       
   }
   
   bool checkBSTPath(Node* now, vector< pair<int, bool> > path)
   {       
       //check firstpass
       if (now->left != NULL && now->data < now->left->data) return false;
       if (now->right != NULL && now->data > now->right->data) return false;       
       
       //validatePaths -> BFS
       if(!validatePath(now->data, path)) return false;
       bool exitNow=false;
       
       if(now->left!=NULL){
           vector< pair<int, bool> > pathLeft = path;
           pathLeft.push_back(make_pair(now->data, false));
           exitNow = !checkBSTPath(now->left, pathLeft);
       }
       
       if( !exitNow &&now->right!=NULL) 
       {
           vector< pair<int, bool> > pathRight = path;
           pathRight.push_back(make_pair(now->data, true));
           exitNow = !checkBSTPath(now->right, pathRight);
       }
       return !exitNow;
              
   }
   
   bool checkBST(Node* root) {
       vector < pair<int, bool> > path;
       return checkBSTPath(root, path);
   }



int main()
{
	//testing
	Node * root = newNode(20);
	root->left = newNode(10);
	root->right = newNode(29);
	root->left->left = newNode(6);
	root->left->right = newNode(21);
	root->right->left= newNode(25);
	root->right->right = newNode(100);
	root->left->left->left = newNode(2);
	root->left->left->right = newNode(8);
	root->left->left->right->left = newNode(7);
	root->left->left->right->right = newNode(9);
	
	cout << (checkBST(root) ? "Yes" : "No" ) << endl;
    
	return 0;
}




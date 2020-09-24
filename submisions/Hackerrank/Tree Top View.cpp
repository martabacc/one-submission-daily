/*
 * Hackerrank
 * Tree Top View
 * https://www.hackerrank.com/challenges/tree-top-view/problem
 *
 * Tree, BFS, Queue
 */

#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
                }

               return root;
           }
        }
#define qc pair<Node*, int>
/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    void topView(Node * root) {
        vector<int> views;
        queue<qc> q;
        int leftMax = -1;
        int rightMax = -1;
        int flag = root->data;
        q.push(make_pair(root, 0));
        while(!q.empty()) {
            qc top = q.front();
            q.pop();
            Node* now = top.first;
            int pos = top.second;
            bool isLeftMost = pos < leftMax;
            bool isRightMost = pos > rightMax;
            if(pos==0 && now->data == flag) {
                leftMax=0;
                rightMax=0;
                views.push_back(now->data);
            } else if(isLeftMost) {
                leftMax=pos;
                views.insert(views.begin(), now->data);
            } else if(isRightMost) {
                rightMax=pos;
                views.push_back(now->data);
            }

            if(now->right != NULL) q.push(make_pair(now->right, pos+1));
            if(now->left != NULL) q.push(make_pair(now->left, pos-1));
        }

        for(int x=0;x<views.size();x++) cout << views[x] << " ";
        cout << endl;
    }
}; //End of Solution

int main() {

    Solution myTree;
    Node* root = NULL;

    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    myTree.topView(root);

    return 0;
}

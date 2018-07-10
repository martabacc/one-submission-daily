#include<bits/stdc++.h>
#define mark -99999
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

pair<int, bool> findShortestHop(struct Node * node, int key1, int key2)
{
	
	if(node == NULL) return make_pair(mark, false);
	
	if(node->val==key1 || node->val==key2)
		//return 1 karna direturn ke parentnya terhitung sekali hop
		return make_pair(1, true);
	
	//render kiri
	pair<int,bool> left = findShortestHop(node->left, key1, key2);
	//render kanan
	pair<int,bool> right = findShortestHop(node->right, key1, key2);
	
	//kalau dua2nya true (sudah ketemu dr kiri dan kanan)
	if( left.second && right.second )
		// change ptr to false (biar ga di inkremen lagi)
		// return sum of two hops
		return make_pair( left.first + right.first , false);
	
	//kalau kiri yang true
	if(left.first!=mark)
		// return ke atas sesuai status , kalau true, diinkrement(berarti pairnya blm ketemu, 
		// tetep kehitung hop++ sampe ketemu lca
		return make_pair( left.first + (left.second ? 1 : 0) , left.second);
	else
		//same but right
		return make_pair(right.first + (right.second ? 1 : 0), right.second);
	
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
    
    int tc;
    cin >> tc;
    while(tc--){
    
	    int x1,x2;
	    cin >> x1 >> x2;
	    pair<int, bool> res = findShortestHop(root,x1, x2);
	    
	    if(res.first > 0) cout << res.first << endl;
	    else cout << "Node yang anda masukkan tidak valid." << endl;	
	}
	
	
}



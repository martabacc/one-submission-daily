pair <int, struct Node*> findLCA(struct Node* root, int n1, int n2)
{
    // Base case
    if (root == NULL) return make_pair(-1,NULL);
 
    // If either n1 or n2 matches with root's key, report
    // the presence by returning root (Note that if a key is
    // ancestor of other, then the ancestor key becomes LCA
    if (root->key == n1 || root->key == n2)
        return make_pair(1,root);
 
    // Look for keys in left and right subtrees
    pair <int, struct Node*> left_lca  = findLCA(root->left, n1, n2);
    pair <int, struct Node*> right_lca = findLCA(root->right, n1, n2);
 
    // If both of the above calls return Non-NULL, then one key
    // is present in once subtree and other is present in other,
    // So this node is the LCA
    if (left_lca.second && right_lca.second ){
        if( left_lca.first == right_lca.first && right_lca.first!=1)
            //return benar
            return make_pair(left_lca.first+1,left_lca);
    }
 
    // Otherwise check if left subtree or right subtree is LCA
    return (left_lca != /*ga ketemu*/) ? 
        //naik ke atas
        make_pair(left_lca.first + 1, left_lca.second ): 

        make_pair(right_lca+1,right_lca.second );
}

# Data Structure: Tree

## Definition

A tree is a *collection* of *entities* called **nodes**.  
Nodes are **connected by edges**.  
Each node **contains a value or data**, and it **may have a child node**.


```cpp
class Node {
    public:
        int data;
        // it may have more than one child
        vector<Node*> child; // can also be called edges

        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};
```

PS: Tree is basically a graph with two pointers, acyclic graph. If it has pointer to its root/parent, then it become a cyclic graph.  

## Types

### Binary Tree

In computer science, a binary tree is a tree data structure in which **each node has at the most two children**, which are referred to as the left child and the right child.

```cpp

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
```

Insertion is done by checking the status of given data and the node's data. If greater, go right, else go left.  
Here is recursion solution of insertion.

```cpp
void insert(Node* ptr, int data) {
  if(ptr == NULL) {
    ptr = new Node(data);
    return ptr;
  }
  if(ptr->data > data){
    if (ptr->left == NULL) ptr->left = new Node(data);
    else insert(ptr->left, data);
  }
  if(ptr->data < data){
    if (ptr->right == NULL) ptr->right = new Node(data);
    else insert(ptr->right, data);
  }
}
```

### AVL
Also called as self-balancing tree.
To be updated

### Trie
> Note: This will be covered more on string subchapter.


## Traversals

### DFS (Depth First Search)

**Key: Stack**

```cpp
Node* dfs(Node* root, int value) {
  stack<Node*> search;
  search.push(root);

  while(!search.empty()) {
    Node* top = search.top();
    search.pop();
    if(top==value) return top;

    if(top->left) search.push(top->left);
    if(top->right) search.push(top->right);
  }
}

```

### BFS (Breadth First Search)

**Key: Queue**

```cpp
Node* bfs(Node* root, int value) {
  queue<Node*> search;
  search.push(root);

  while(!search.empty()) {
    Node* top = search.front();
    search.pop();
    if(top==value) return top;

    if(top->left) search.push(top->left);
    if(top->right) search.push(top->right);
  }
}

```

## Orderings

#### Pre Order (SLR)
**Key: SLR (Self, Left, Right)**

```cpp
vector<int> result;
void preorder(Node* root) {
  if(root==null) return;
  preOrderResult.push(root->data);
  preOrder(root->left);
  preOrder(root->right);
}

```

#### In Order (LSR)
**Key: LSR (Left, Self, Right)**

```cpp
vector<int> result;
void preorder(Node* root) {
  if(root==null) return;
  preOrder(root->left);
  preOrderResult.push(root->data);
  preOrder(root->right);
}

```

#### Post Order (LRS)
**Key: LSR (Left, Right, Self)**

```cpp
vector<int> result;
void preorder(Node* root) {
  if(root==null) return;
  preOrder(root->left);
  preOrder(root->right);
  preOrderResult.push(root->data);
}

```


## Trivias

### Lowest Common Ancestor

Should be recursive.

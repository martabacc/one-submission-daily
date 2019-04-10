# Data Structure: Heap

## Definition

A heap is a tree-based data structure in **which all the nodes of the tree are in a specific order**.

The maximum number of children of a node in a heap depends on the type of heap. However, in the more commonly-used heap type, there are at most children of a node and it's known as a Binary heap.

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

## Types

### Binary Heap

### Max Heap

### Min Heap

## Traversals

## Orderings


## Trivias

### Lowest Common Ancestor

Should be recursive.

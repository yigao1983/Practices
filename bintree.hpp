#ifndef BINTREE_HPP
#define BINTREE_HPP

#include <iostream>
#include <cstdlib>
#include <queue>

template <class T>
class BinTree {
  
public:
  
  BinTree() : root(NULL)
  {}
  
  virtual ~BinTree()
  {
    if (root) {
      delete root;
      root = NULL;
    }
  }
  
  virtual void add_node(T v)
  {
    if (!root) {
      root = new BinNode(v);
    } else {
      append(root, v);
    }
  }
  
  void traverse_io()
  { traverse_subtree(root); }
  
  void find_leaves()
  {
    std::queue<T> leaves;
    
    if (root) {
      add_leaf(root, leaves);
    }
    
    while (!leaves.empty()) {
      std::cout << leaves.front() << std::endl;
      leaves.pop();
    }
  }
  
protected:
  
  class BinNode {
    
  public:
    
    BinNode(T v) : value(v), left(NULL), right(NULL)
    {}
    
    virtual ~BinNode()
    {
      if (left) {
	delete left;
	left = NULL;
      }
      if (right) {
	delete right;
	right = NULL;
      }
    }
    
    T value;
    BinNode *left, *right;
    
    //friend class BinTree<T>;
  };
  
  BinNode *root;
  
  void append(BinNode *ptr, T v)
  {
    if (v < ptr->value) {
      if (!ptr->left) {
        BinNode *node = new BinNode(v);
        ptr->left = node;
      } else {
        append(ptr->left, v);
      }
    } else if (v > ptr->value) {
      if (!ptr->right) {
        BinNode *node = new BinNode(v);
        ptr->right = node;
      } else {
        append(ptr->right, v);
      }
    }
  }
  
  void traverse_subtree(BinNode *ptr)
  {
    if (ptr->left) {
      traverse_subtree(ptr->left);
    }
    
    std::cout << ptr->value << std::endl;
    
    if (ptr->right) {
      traverse_subtree(ptr->right);
    }
  }
  
  void add_leaf(BinNode *ptr, std::queue<T> &q)
  {
    if (!ptr->left and !ptr->right) {
      q.push(ptr->value);
    } else {
      if (ptr->left)  add_leaf(ptr->left, q);
      if (ptr->right) add_leaf(ptr->right, q);
    }
  }
};

#endif

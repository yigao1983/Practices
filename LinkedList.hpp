#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

template <class T>
class LinkedList {
  
public:
  
  LinkedList() : first(NULL), last(NULL)
  {}
  
  ~LinkedList()
  {
    Node *curr = first;
    
    while (curr) {
      Node *next = curr->next;
      delete curr;
      curr = next;
    }
    last = NULL;
  }
  
  void push(T v)
  {
    Node *curr = new Node(v);
    
    if (not first) {
      first = curr;
    } else {
      last->next = curr;
    }
    last = curr;
  }
  
  void traverse() const
  {
    Node *curr = first;
    
    while (curr) {
      std::cout << curr->val << std::endl;
      curr = curr->next;
    }
  }
  
private:
  
  class Node {
    
  public:
    
    Node(T v) : val(v), next(NULL)
    {}
    
  private:
    T val;
    Node *next;
    
    friend class LinkedList<T>;
  };
  
  Node *first, *last;
};

#endif

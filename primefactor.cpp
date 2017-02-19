#include <iostream>
#include "bintree.hpp"

using namespace std;

class PrimeFactorTree : public BinTree<int> {
  
public:
  
  PrimeFactorTree(int num) : root_val(num)
  { root = new BinTree<int>::BinNode(root_val); }
  
  void factorize()
  { spawn_nodes(root); }
  
protected:
  
  int root_val;
  
  void spawn_nodes(BinNode *ptr)
  {
    int n = ptr->value / 2;
    
    for (int i = n; i >= 1; i--) {
      if (ptr->value % i == 0) {
        int j = ptr->value / i;
        if (i > 1 && j > 1) {
          ptr->left  = new BinNode(i);
          ptr->right = new BinNode(j);
          spawn_nodes(ptr->left);
          spawn_nodes(ptr->right);
        }
        break; // Important!
      }
    }
  }
};

int main()
{
  PrimeFactorTree factors = PrimeFactorTree(18);
  
  factors.factorize();
  factors.find_leaves();
  
  return 0;
}

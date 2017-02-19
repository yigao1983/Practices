#include <iostream>
#include "bintree.hpp"

using namespace std;

int main()
{
  const int N = 10;
  BinTree<int> tree;
  
  for (int i = 0; i < N; ++i) {
    int num = rand() % 20;
    cout << num << endl;
    tree.add_node(num);
  }
  
  //tree.traverse_io();
  
  //tree.find_leaves();
  
  return 0;
}
